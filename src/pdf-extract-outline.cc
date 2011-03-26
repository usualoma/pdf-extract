#include <iostream>
#include "pdf-extract.h"

using namespace std;

static void print_title(gchar *title) {
    cout << title << endl;
}

int main(int argc, char *argv[]) {
    if (argc == 1) {
        cerr << "Usage: " << argv[0] << " [file ...]" << endl;
    }

    for (int i = 1; i < argc; i++) {
        GSList *titles = pdf_extract_outline(argv[i]);
        g_slist_foreach(titles, (GFunc)print_title, titles);
    }

    return 0;
}
