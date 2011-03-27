#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include "pdf-extract.h"

using std::string;
using std::vector;
using std::for_each;

static void print_title(string *title) {
    std::cout << *title << std::endl;
}

static void extract_each_file(const char *str) {
    string filename(str);
    vector<string*> *titles = pdf_extract::outline(filename);
    for_each(titles->begin(), titles->end(), print_title);
}

int main(int argc, char *argv[]) {
    if (argc == 1) {
        std::cerr << "Usage: " << argv[0] << " [file ...]" << std::endl;
        return 0;
    }

    for_each(argv+1, argv+argc, extract_each_file);

    return 0;
}
