#include <iostream>

using namespace std;

int modularExp(int b, int n, int m) {
    // compute (b^n) mod m
    int x = 1;
    int power = b % m;

    while (n > 0) {
        if (n % 2 == 1) x = (x * power) % m;
        power = (power * power) % m;
        n = n >> 1;
    }

    return x;
}

int main (void) { }