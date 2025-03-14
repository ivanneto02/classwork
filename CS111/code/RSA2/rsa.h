#include <cmath>

// Method shown in class where you check
// congruence of integers up to sqrt(n)
bool isPrime(int n) {

    // Check if it's prime 
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }    
    return true;
}

void findPQ(int n, int &p, int &q) {
    /*
    // My own algorithm - Ivan
    for (int i = 2; i < n; i++) {
        // Check if n is divisible by i
        if (n % i == 0) {
            
            int tmp_p = i;
            int tmp_q = n / i;

            // Check if both are prime
            if ( isPrime(tmp_p) && isPrime(tmp_q) ) {
                p = tmp_p;
                q = tmp_q;
                return;
            }
        }
    }
    return;
    */

    // Exclude 1 because every number mod 1 is congruent to 0
    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            if (i < (n/i)) {
                p = i; 
                q = n / i; 
            }
            else {
                p = n / i;
                q = i;  
            }
        return; 
        } 
    }
}

// Eucledian Algorithm
int gcd(int a, int b) {
    if (a == 0) {
        return b;
    }
    if (a < b) {
        int tmp = a;
        a = b;
        b = tmp;
    }
    return gcd(a % b, b); 
}

// Determines whether the given public key is valid/invalid
bool PubKeyValid(int e, int n, int p, int q) {

    int phi = (q-1) * (p-1); 

    /*
    Checking:
        2) e is coprime with phi
        3) q is prime (ASSUMED)
        4) p is prime (ASSUMED)
    */
    if (p != q) {

        if (gcd(e, phi) == 1) {
            return true; 
        }
    }
    return false; 
}

int find_d(int e, int p, int q) {

    // 1 <= d < n
    // d = e^-1 mod(p-1)(q-1)
    // gcd(e, phi) = 1 
    int d = 1; 
    int n = p * q; 
    int phi = (q-1) * (p-1);

    while (d < n)  {
        if ((d * e) % phi == 1){
            return d; 
        }
        d++; 
    }

    return d; 
}