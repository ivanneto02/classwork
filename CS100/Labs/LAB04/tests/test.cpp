#include <gtest/gtest.h>
#include <cmath>
#include "../header/rectangle.hpp"

using namespace std;

// Test suite 1
TEST(ConstructorTests, negativeValues) {

	Rectangle rect = Rectangle(-3, -4);
	ASSERT_EQ(0, rect.get_width());
	ASSERT_EQ(0, rect.get_height());
}

TEST(ConstructorTests, noValues) {

	Rectangle rect = Rectangle();
	ASSERT_EQ(0, rect.get_width());
	ASSERT_EQ(0, rect.get_height());
}

TEST(ConstructorTests, posIntVals) {

	Rectangle rect = Rectangle(7, 5);
	ASSERT_EQ(7, rect.get_width());
	ASSERT_EQ(5, rect.get_height());
}

TEST(ConstructorTests, posNegMix) {

	Rectangle rect = Rectangle(-7, 5);
	ASSERT_EQ(0, rect.get_width());
	ASSERT_EQ(5, rect.get_height());

	rect = Rectangle(5, -7);
	ASSERT_EQ(5, rect.get_width());
	ASSERT_EQ(0, rect.get_height());
}

TEST(ConstructorTests, Zeros) {

	Rectangle rect = Rectangle(0, 0);
	ASSERT_EQ(0, rect.get_width());
	ASSERT_EQ(0, rect.get_height());
}

// Test suite 2
TEST(AreaTests, negativeValues) {

	Rectangle rect = Rectangle(-4, -6);
	ASSERT_EQ(0, rect.area());
}

TEST(AreaTests, noValues) {

	Rectangle rect = Rectangle();
	ASSERT_EQ(0, rect.area());
}

TEST(AreaTests, posIntVals) {

	Rectangle rect = Rectangle(10, 10);
	ASSERT_EQ(100, rect.area());
}

TEST(AreaTest, Zeros) {

	Rectangle rect = Rectangle(0, 0);
	ASSERT_EQ(0, rect.area());
} 

// Test suite 3
TEST(PerTests, negativeValues) {

	Rectangle rect = Rectangle(-10, -10);
	ASSERT_EQ(0, rect.perimeter());
}

TEST(PerTests, noValues) {

	Rectangle rect = Rectangle();
	ASSERT_EQ(0, rect.perimeter());
}

TEST(PerTests, posIntVals) {

	Rectangle rect = Rectangle(13, 14);
	ASSERT_EQ(54, rect.perimeter());
}

TEST(PerTests, posNegMix) {

	Rectangle rect = Rectangle(-3, 10);
	ASSERT_EQ(0, rect.perimeter());
}

int main(int argc, char** argv) {

	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
	return 0;
}
