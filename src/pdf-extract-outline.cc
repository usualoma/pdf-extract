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

template <typename T>
static void delete_object(T *obj) {
    delete obj;
}

template <typename T, typename C>
static void delete_container(C *container) {
    for_each(container->begin(), container->end(), delete_object<T>);
    delete container;
}

static void extract_file(const char *str) {
    string filename(str);
    vector<string*> *titles = pdf_extract::outline(filename);

    for_each(titles->begin(), titles->end(), print_title);

    delete_container<string>(titles);
}

int main(int argc, char *argv[]) {
    if (argc == 1) {
        std::cerr << "Usage: " << argv[0] << " [file ...]" << std::endl;
        return 0;
    }

    for_each(argv+1, argv+argc, extract_file);

    return 0;
}
