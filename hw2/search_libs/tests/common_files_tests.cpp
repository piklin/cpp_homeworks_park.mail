//
// Created by Evgeny Kharitonov on 28.10.2020.
//

#include <gtest/gtest.h>

extern "C" {

}


int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
