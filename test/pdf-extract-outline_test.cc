#include <libgen.h>
#include <string>
#include <vector>
#include "pdf-extract.h"

#include <gtest/gtest.h>

static char* program;
static char* test_dir;

TEST(OutlineTest, TestData) {
    using std::vector;
    using std::string;

    string filename("");
    filename.
        append(test_dir).
        append("/pdf/test.pdf");

    vector<string*> *titles = pdf_extract::outline(filename);

    EXPECT_EQ(2, titles->size());
    EXPECT_EQ("テスト", *titles->at(0));
    EXPECT_EQ("てすと", *titles->at(1));
}

int main(int argc, char **argv) {
    program  = argv[0];
    test_dir = dirname(program);

    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
