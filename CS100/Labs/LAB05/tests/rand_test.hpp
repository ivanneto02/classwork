#ifndef __RAND_TEST_HPP__
#define __RAND_TEST_HPP__

#include "gtest/gtest.h"
#include "../headers/Rand.hpp"
// #include <iostream>
// using namespace std; 

TEST(RandEvaluate, Seed0) {

	unsigned seed = 0; 
	Rand* test = new Rand(seed); 
	srand(seed); 
	EXPECT_DOUBLE_EQ(test->evaluate(), rand() % 100); 

}

TEST(RandStringify, Seed0) {
	unsigned seed = 0;
	Rand* test = new Rand(seed); 
	srand(seed); 
	EXPECT_EQ(test->stringify(), "(83.00)"); 
}
 

#endif


