#include <string>
#include <vector>
#include "pdf-extract.h"

#include <poppler/PDFDoc.h>
#include <poppler/PDFDocFactory.h>
#include <poppler/UnicodeMap.h>
#include <poppler/goo/GooList.h>
#include <poppler/Outline.h>
#include <poppler/GlobalParams.h>

namespace pdf_extract {
    using std::vector;
    using std::string;

    static string* unicode_to_char(Unicode *unicode, int len) {
        static GlobalParams *globalParams = NULL;
        if (globalParams == NULL) {
            globalParams = new GlobalParams();
        }

	    static UnicodeMap *uMap = NULL;
	    if (uMap == NULL) {
		    GooString *enc = new GooString("UTF-8");
		    uMap = globalParams->getUnicodeMap(enc);
		    uMap->incRefCnt();
		    delete enc;
	    }

	    GooString gstr;
	    char buf[8];
	    int i, n;

	    for (i = 0; i < len; ++i) {
		    n = uMap->mapUnicode(unicode[i], buf, sizeof(buf));
		    gstr.append(buf, n);
	    }

	    return new string(gstr.getCString());
    }

    static PDFDoc* new_pdf_doc(string filename) {
        GooString filename_g(filename.c_str());
        return PDFDocFactory().createPDFDoc(filename_g);
    }

    vector<string*>* outline(string filename) {
        vector<string*> *titles = new vector<string*>();

        PDFDoc *doc = new_pdf_doc(filename);
        if (! doc->isOk()) {
            return titles;
        }

        Outline *outline = doc->getOutline();
        GooList *items   = outline->getItems();

        for (int i = 0, len = items->getLength(); i < len; i++) {
            OutlineItem *item = (OutlineItem*)items->get(i);
            Unicode *unicode  = item->getTitle();
            string *title     =
                unicode_to_char(unicode, item->getTitleLength());

            titles->push_back(title);
        }

        delete doc;

        return titles;
    }
}
