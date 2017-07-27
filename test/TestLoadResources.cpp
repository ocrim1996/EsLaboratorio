//
// Created by Mirco Ceccarelli on 27/07/17.
//

#include "gtest/gtest.h"
#include "../LoadResources.h"

TEST(TestLoadResources, testNoFileNamesProvided) {
    std::vector<const char*> vector;
    LoadResources loader;
    loader.load(vector);
    ASSERT_EQ(loader.getNumberOfResources(), 0);
}

TEST(TestLoadResources, fileNamesProvided) {

    std::vector<const char*> vector;
    vector.push_back("ciao.png");
    LoadResources loader;
    loader.load(vector);
    ASSERT_FALSE(loader.getNumberOfResources()==0);
}