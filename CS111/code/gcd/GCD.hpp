#ifndef GCD_HPP
#define GCD_HPP

class GCD {

    public:
        int a;
        int b;

        GCD(int a, int b) : a(a), b(b) {};

        // Returns the greatest common denominator
        int gcd();

    private:
        // Recursive helper for gcd()
        int compute(int, int);
};

#endif /* GCD_HPP */