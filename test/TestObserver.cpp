//
// Created by Mirco Ceccarelli on 27/07/17.
//

#include "gtest/gtest.h"
#include "../LoadResources.h"
#include "../ConcreteObserver.h"

TEST(TestObserver, testFileName) {

    LoadResources loader;
    ConcreteObserver observer(&loader);

    std::vector<const char*> vector;
    vector.push_back("ciao.jpg");
    loader.load(vector);

    ASSERT_EQ(observer.resources->getFilename(), "ciao.jpg");
}

TEST(TestObserver, testFileSize) {

    LoadResources loader;
    ConcreteObserver observer(&loader);

    std::vector<const char*> vector;
    vector.push_back("logo.png");
    loader.load(vector);

    ASSERT_EQ(observer.resources->getFilesize(), 32543);
}

TEST(TestObserver, testLoaded) {

    LoadResources loader;
    ConcreteObserver observer(&loader);

    std::vector<const char*> vector;
    vector.push_back("logo.png");
    loader.load(vector);

    ASSERT_TRUE(observer.resources->didLoadFile());
}

TEST(TestObserver, testNoLoaded) {

    LoadResources loader;
    ConcreteObserver observer(&loader);

    std::vector<const char*> vector;
    vector.push_back("ciao.jpg");
    loader.load(vector);

    ASSERT_FALSE(observer.resources->didLoadFile());
}