#include <iostream>

using namespace std;

int gcd(int a, int b) {
    if (a < b) gcd(b, a);
    else if (b == 0) return a;
    else gcd(b, a % b);
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int main(void) { }