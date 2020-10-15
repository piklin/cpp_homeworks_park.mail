#include <gtest/gtest.h>
#include <iostream>
#include <cerrno>
#include <fstream>

extern "C" {
    #include "r_w_computers.h"
}

std::string path;

bool isEqualFiles(const std::string &file1, const std::string &file2) {
    std::ifstream fin1(file1);
    std::ifstream fin2(file2);
    if (fin1 && fin2) {
        char ch1, ch2;
        while (fin1.get(ch1) && fin2.get(ch2)) {
            if (ch1 != ch2) {
                return false;
            }
        }
        return true;
    }
    return false;
}


TEST(rw_comp, reading_test1) {
    FILE *in = fopen("../tests/test_data/rw_comp__reading_test1", "r");
    ASSERT_TRUE(in);

    struct node node = {};
    EXPECT_FALSE(scan_comp(in, &node));
    EXPECT_STREQ(node.data.brand, "Apple");
    EXPECT_EQ(node.data.core_count, 8);
    EXPECT_EQ(node.data.clock_frequency, 10);
    EXPECT_EQ(node.data.ram_count, 20);
}

TEST(rw_comp, reading_test2) {
    FILE *in = fopen("../tests/test_data/rw_comp__reading_test2", "r");
    ASSERT_TRUE(in);
    struct node node = {};
    EXPECT_TRUE(scan_comp(in, &node));
}

TEST(rw_comp, reading_test3) {
    FILE *in = fopen("../tests/test_data/rw_comp__reading_test3", "r");
    ASSERT_TRUE(in);
    struct node node = {};
    EXPECT_TRUE(scan_comp(in, &node));
}

TEST(rw_comp, reading_test4) {
    FILE *in = fopen("../tests/test_data/rw_comp__reading_test4", "r");
    ASSERT_TRUE(in);
    struct node node = {};
    EXPECT_FALSE(scan_comp(in, &node));
    EXPECT_TRUE(node.data.brand[19]);
    EXPECT_STREQ(node.data.brand, "abcdefghijklmnopqrst");
    EXPECT_EQ(node.data.core_count, 10);
    EXPECT_EQ(node.data.clock_frequency, 20);
    EXPECT_EQ(node.data.ram_count, 30);
}

TEST(rw_comp, writing_test1) {
    std::string out_file("../tests/test_data/rw_comp__writing_test1_tmp");
    std::string tst_file("../tests/test_data/rw_comp__writing_test1");
    FILE *out = fopen(out_file.data(), "a");
    ASSERT_TRUE(out);
    struct node node = {"Apple", 8, 10, 20};
    print_comp(out, &node);
    fclose(out);
    EXPECT_TRUE(isEqualFiles(out_file, tst_file));
    std::remove(out_file.data());
}



int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}