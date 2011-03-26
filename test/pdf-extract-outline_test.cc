#include <glib.h>
#include "pdf-extract.h"

#include <gtest/gtest.h>

TEST(OutlineTest, TestData) {
    GSList *titles = pdf_extract_outline("pdf/test.pdf");
    EXPECT_EQ(2, g_slist_length(titles));
    EXPECT_EQ(0, strcmp((char*)g_slist_nth(titles, 0)->data, "テスト"));
    EXPECT_EQ(0, strcmp((char*)g_slist_nth(titles, 1)->data, "てすと"));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
