//
// Created by Mirco Ceccarelli on 27/07/17.
//

#include "gtest/gtest.h"
#include "../File.h"

TEST(TestFile, testNonExistentResource) {
    ASSERT_THROW(File file("ciao.jpg"), runtime_error);
}

TEST(TestFile, testExistentResource) {
    ASSERT_NO_THROW(File file("logo.png"));
}

TEST(TestFile, testSizeForExistentFile) {
    File file("logo.png");
    ASSERT_FALSE(file.getSizeInBytes() == 0);
}