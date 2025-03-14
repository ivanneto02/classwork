#include "rsa.h"
#include <vector>
#include <gtest/gtest.h>
#include <iostream>

using namespace std;

// Write some test cases...

// Testing whether isPrime(int) : bool works for primes
TEST(ValidityTests, isPrimePrimes) {
    
    vector<int> primes{1, 2, 3, 7, 11, 13, 17, 23, 31};

    // True statements
    for (int i = 0; i < primes.size(); i++) {

        ASSERT_TRUE(isPrime(primes.at(i)));
    }

}

// Testing whether isPrime(int) : bool works for nonprimes
TEST(ValidityTests, isPrimeNonPrimes) {

    // Some nonprime numbers
    vector<int> nonprimes{4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 9, 15, 25, 27, 32};

    // False statements
    for (int i = 0; i < nonprimes.size(); i++) {

        ASSERT_FALSE(isPrime(nonprimes.at(i)));
    }
}

// Test whether findPQ works
TEST(ValidityTests, findPQGivenValidN) {

    // Some prime numbers higher than 1
    vector<int> primes{2, 3, 7, 11, 13, 17, 23, 31};

    int p = 0;
    int q = 0;
    int n = 0;

    for (int i = 0; i < primes.size(); i++) {

        for (int j = 0; j < primes.size(); j++) {
            
            if (primes.at(i) == primes.at(j)) {
                continue;
            }

            n = primes.at(i) * primes.at(j);

            findPQ(n, p, q);

            ASSERT_TRUE( (q == primes.at(i)) || (p == primes.at(i)) );
            ASSERT_TRUE( (q == primes.at(j) ) || (p == primes.at(j)) );
        }
    }

}

TEST(ValidityTests, gcd) {

    int a; int b;

    a = 10; b = 5;
    ASSERT_EQ(5, gcd(a, b));

    a = 24; b = 18;
    ASSERT_EQ(6, gcd(a, b));

    a = 17; b = 23;
    ASSERT_EQ(1, gcd(a, b));

    a = 45; b = 27;
    ASSERT_EQ(9, gcd(a, b));
}

TEST(ValidityTests, pubKeyValid) {
    // IMPORTANT: we are assuming that p and q are already prime since
    // we had to find them

    int e; int q; int p;

    e = 5; q = 7; p = 13;
    ASSERT_TRUE(PubKeyValid(e, p*q, p, q));

    e = 7; q = 29 ; p = 13;
    ASSERT_FALSE(PubKeyValid(e, p*q, p, q));

    e = 10; q = 7; p = 13;
    ASSERT_FALSE(PubKeyValid(e, p*q, p, q));
    
    e = 8; q = 11; p = 41;
    ASSERT_FALSE(PubKeyValid(e, p*q, p, q));

    e = 8; q = 13; p = 17;
    ASSERT_FALSE(PubKeyValid(e, p*q, p, q));

    e = 5; q = 5; p = 11;
    ASSERT_FALSE(PubKeyValid(e, p*q, p, q));
}

// Testing whether
int main(int argc, char** argv) {
    
    // Initialize Google test
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}