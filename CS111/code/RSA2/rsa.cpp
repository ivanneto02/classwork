#include <iostream>
#include <cmath>            // for sqrt(), pow()
#include <vector> 
#include <stdio.h>          // for exit(1)
using namespace std;

void findPQ(int n, int &p, int &q);  
bool PubKeyValid(int e, int n, int p, int q); 
bool isPrime(int n); 
int gcd(int a, int b); 

// finding d 
vector<int> gcd2(int a, int b); 
int find_d(int e, int p, int q); 

// decrypting stuff 
int decrypt_int(int C, int d, int n); 
char decrypt_char(int M); 


int main() {
    int e = 0;
    int n = 0;
    int m = 0;

    cin >> e >> n >> m; 
    int p=0, q=0;

    int C;
    vector<int> en_message;
    for (int i = 0; i < m; i++) {
        cin >> C;
        en_message.push_back(C);
    }

    findPQ(n, p, q); 
    if (!PubKeyValid(e, n, p, q)) {
        cout << "Public key not valid!" << endl;
        return 0; 
    }

    int phi = (p-1)*(q-1); 

    int d = find_d(e, p, q); 

    cout << p  << " " << q << " " << phi << " " << d << endl; 

    vector<int> message;
    for (int i = 0; i < m; i++) {
        C = en_message.at(i);
        int M = decrypt_int(C, d, n);
        message.push_back(M); 
    }

    for (int i = 0; i < m; i++) {
        cout << message.at(i) << " "; 
    }
    cout << endl; 

    for (int i = 0; i < m; i++) {
        cout << decrypt_char(message.at(i)); 
    }

    cout << endl; 
    

    return 0;
    
}

void findPQ(int n, int &p, int &q) {

    for (int i = 2; i < n/2 + 1; i++) {
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


// Extended Eucledian Algorithm
vector<int> gcd2(int a, int b) {
    
    if (a == b) {
        return vector<int>{a, 0, 1};
    }
    if (a > b) {
        vector<int> ret = gcd2(a - b, b);
        return vector<int>{ret[0], ret[1], ret[2] - ret[1]};
    }
    else {
        vector<int> ret2 = gcd2(b - a, a);
        return vector<int>{ret2[0], ret2[2] - ret2[1], ret2[1]};
    }
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


// for decrypting the message 
int decrypt_int(int C, int d, int n) {
    // M=C^d (mod n)
    // M = pow(C, d);

    int M = 1;  

    for (int i = 0; i < d/2; i++) {
        int temp = pow(C, 2); 
        temp = temp % n; 
        M = M * temp; 
        M = M % n;
    }

    M = (M * C) % n; 

    return M; 
}

char decrypt_char(int M) { 
    if (M == 29) {
        return ' '; 
    }
    if (M == 30) {
        return 34; 
    }
    if (M == 31) {
        return '.'; 
    }
    if (M == 32) {
        return ','; 
    }
    if (M == 33) {
        return 39; 
    }
    else {
        return M + 62; 
    }

}