#include <glib.h>
#include <poppler/PDFDoc.h>
#include <poppler/UnicodeMap.h>
#include <poppler/goo/GooList.h>
#include <poppler/Outline.h>
#include <poppler/GlobalParams.h>

static gchar* unicode_to_char(Unicode *unicode, int len) {
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
	gchar buf[8];
	int i, n;

	for (i = 0; i < len; ++i) {
		n = uMap->mapUnicode(unicode[i], buf, sizeof(buf));
		gstr.append(buf, n);
	}

	return g_strdup(gstr.getCString());
}

GSList* pdf_extract_outline(char *filename) {
    GSList *titles = NULL;

    PDFDoc *doc;
    Outline *outline;
    GooList *items;
    OutlineItem *item;
    Unicode *str;
    gchar *title;

    GooString *filename_g;
    filename_g = new GooString(filename);
    doc = new PDFDoc(filename_g, 0, 0);
    delete filename_g;

    if (doc->getErrorCode()) {
        return NULL;
    }

    outline = doc->getOutline();
    items = outline->getItems();

    int i;
    for (i = 0; i < items->getLength(); ++i) {
        item = (OutlineItem*)items->get(i);
        str  = item->getTitle();
	    title = unicode_to_char(str, item->getTitleLength());
        titles = g_slist_append(titles, title);
    }

    return titles;
}
