#pragma once
#include "TextFixture.h"
struct Param {
    const char* argument;
    int expected;
    Param (char* argument, int expected) :
        argument(argument), expected(expected) {}


};
class TestFixtureWithParam :
    public TextFixture, public ::testing::WithParamInterface<Param>
{


   
};

