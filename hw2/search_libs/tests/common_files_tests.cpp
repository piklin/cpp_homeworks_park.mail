//
// Created by Evgeny Kharitonov on 28.10.2020.
//

#include <gtest/gtest.h>

extern "C" {
    #include "for_searchers.h"
}


int comp(ssize_t first, ssize_t second) {
    return first < second;
}


TEST(finding_sequences, test1) {
    ssize_t a[10] = {-3, 5, 7, 1, 3, 8, 9, -2, 0, 5};
    struct proc_res result = {};
    int res = finding_sequences(a, 10, comp, &result);
    ASSERT_EQ(res, 0);
    ASSERT_EQ(result.start_seq_length, 3);
    ASSERT_EQ(result.end_seq_length, 3);
    ASSERT_EQ(result.max_seq_length, 4);
    ASSERT_EQ(result.max_seq_start, 3);
    ASSERT_EQ(result.start_value, -3);
    ASSERT_EQ(result.end_value, 5);
}

TEST(finding_sequences, test2) {
    ssize_t a[10] = {3, 5, 6, -1, 5, 1, 1, 5, 8, 3};
    struct proc_res result = {};
    int res = finding_sequences(a, 10, comp, &result);
    ASSERT_EQ(res, 0);
    ASSERT_EQ(result.start_seq_length, 3);
    ASSERT_EQ(result.end_seq_length, 1);
    ASSERT_EQ(result.max_seq_length, 3);
    ASSERT_EQ(result.max_seq_start, 0);
    ASSERT_EQ(result.start_value, 3);
    ASSERT_EQ(result.end_value, 3);
}

TEST(finding_sequences, test3) {
    ssize_t a[5] = {4, 6, 7, 8, 9};
    struct proc_res result = {};
    int res = finding_sequences(a, 5, comp, &result);
    ASSERT_EQ(res, 0);
    ASSERT_EQ(result.start_seq_length, 5);
    ASSERT_EQ(result.end_seq_length, 5);
    ASSERT_EQ(result.max_seq_length, 5);
    ASSERT_EQ(result.max_seq_start, 0);
    ASSERT_EQ(result.start_value, 4);
    ASSERT_EQ(result.end_value, 9);
}

TEST(finding_sequences, test4) {
    ssize_t a[8] = {3, 5, 1, -1, 3, 4, 7, 5};
    struct proc_res result = {};
    int res = finding_sequences(a, 8, comp, &result);
    ASSERT_EQ(res, 0);
    ASSERT_EQ(result.start_seq_length, 2);
    ASSERT_EQ(result.end_seq_length, 1);
    ASSERT_EQ(result.max_seq_length, 4);
    ASSERT_EQ(result.max_seq_start, 3);
    ASSERT_EQ(result.start_value, 3);
    ASSERT_EQ(result.end_value, 5);
}

TEST(finding_maximum_sequence_proc_count, test1) {
    ssize_t a[8] = {3, 5, 1, -1, 3, 4, 7, 5};
    size_t start = 0;
    size_t len = 0;
    int res = finding_maximum_sequence_proc_count(a, 8, &start, &len, comp, 1);
    ASSERT_EQ(res, 0);
    ASSERT_EQ(start, 3);
    ASSERT_EQ(len, 4);
}

TEST(finding_maximum_sequence_proc_count, test2) {
    ssize_t a[8] = {2, 7, 8, 1, 3, 2, 7, 5};
    size_t start = 0;
    size_t len = 0;
    int res = finding_maximum_sequence_proc_count(a, 8, &start, &len, comp, 1);
    ASSERT_EQ(res, 0);
    ASSERT_EQ(start, 0);
    ASSERT_EQ(len, 3);
}

TEST(finding_maximum_sequence_proc_count, test3) {
    ssize_t a[10] = {2, 1, 2, 4, 5, 8, 10, 12, 15, 1};
    size_t start = 0;
    size_t len = 0;
    int res = finding_maximum_sequence_proc_count(a, 10, &start, &len, comp, 3);
    ASSERT_EQ(res, 0);
    ASSERT_EQ(start, 1);
    ASSERT_EQ(len, 8);
}

TEST(finding_maximum_sequence_proc_count, test4) {
    ssize_t a[10] = {2, 1, 2, 10, 5, 8, 10, 12, 15, 1};
    size_t start = 0;
    size_t len = 0;
    int res = finding_maximum_sequence_proc_count(a, 10, &start, &len, comp, 3);
    ASSERT_EQ(res, 0);
    ASSERT_EQ(start, 4);
    ASSERT_EQ(len, 5);
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
