//
// Created by Evgeny Kharitonov on 29.10.2020.
//

#include <gtest/gtest.h>

extern "C" {
    #include "lib_funcs.h"
}


int comp(ssize_t first, ssize_t second) {
    return first < second;
}

TEST(finding_maximum_sequence, test1) {
    ssize_t a[10] = {2, 1, 2, 10, 5, 8, 10, 12, 15, 1};
    size_t start = 0;
    size_t len = 0;
    int res = finding_maximum_sequence(a, 10, &start, &len, comp);
    ASSERT_EQ(res, 0);
    ASSERT_EQ(start, 4);
    ASSERT_EQ(len, 5);
    ASSERT_EQ(5, 5);
}


int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
