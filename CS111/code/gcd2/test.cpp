#include "gtest/gtest.h"
#include "main.h"

TEST(EuclidSlow, ZerosInEither) {
	
	int res;
		
	// Some cases
	res = euclid_slow(0, 10);
	EXPECT_EQ(10, res);

	res = euclid_slow(10, 0);
	EXPECT_EQ(10, res);

	res = euclid_slow(0, 0);
	EXPECT_EQ(0, res);

	// Just to be confident
	for (int i = 0; i < 10; i++) {
		res = euclid_slow(0, i);
		EXPECT_EQ(i, res);
	}

	for (int i = 0; i < 10; i++) {
		res = euclid_slow(i, 0);
		EXPECT_EQ(i, res);
	}

}

TEST(EuclidSlow, KnownBatch) {
	int res;

	res = euclid_slow(1034, 222);
	EXPECT_EQ(2, res);

	res = euclid_slow(15, 100);
	EXPECT_EQ(5, res);

	res = euclid_slow(6, 12);
	EXPECT_EQ(6, res);

	res = euclid_slow(13, 69);
	EXPECT_EQ(1, res);

	res = euclid_slow(15, 45);
	EXPECT_EQ(15, res);
}

TEST(EuclidFast, ZerosInEither) {
	int res;

    // Some cases
    res = euclid_fast(0, 10);
    EXPECT_EQ(10, res);

    res = euclid_fast(10, 0);
    EXPECT_EQ(10, res);

    res = euclid_fast(0, 0);
    EXPECT_EQ(0, res);

    // Just to be confident
    for (int i = 0; i < 10; i++) {
        res = euclid_fast(0, i);
        EXPECT_EQ(i, res);
    }

    for (int i = 0; i < 10; i++) {
        res = euclid_fast(i, 0);
        EXPECT_EQ(i, res);
    }
}

TEST(EuclidFast, KnownBatch) {
    int res;

    res = euclid_fast(1034, 222);
    EXPECT_EQ(2, res);

    res = euclid_fast(15, 100);
    EXPECT_EQ(5, res);

    res = euclid_fast(6, 12);
    EXPECT_EQ(6, res);

    res = euclid_fast(13, 69);
    EXPECT_EQ(1, res);

    res = euclid_fast(15, 45);
    EXPECT_EQ(15, res);
}

int main(int argc, char **argv) {

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
