#include <iostream>

using namespace std;

int euclid_slow(int a, int b) {

	if (a == b) {
		return a;
	}
	
	if (a < b) {
		int tmp = a;
		a = b;
		b = tmp;
	}
	
	return euclid_slow(a - b, b);
}

int euclid_fast(int a, int b) {
	
	if (b == 0) {
		return a;
	}
	if (a == 0) {
		return b;
	}
	if (a < b) {
		int tmp = a;
		a = b;
		b = tmp;
	}
	
	return euclid_fast(a % b, b);
}
