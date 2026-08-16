#include <iostream>
using namespace std;

#define culll const unsigned long long &
#define ull unsigned long long
ull t;

ull qpow(culll a, culll b, culll m) {
    if(b == 1) return a % m;
    t = qpow(a, b/2, m) % m;
    if (b % 2 == 1) return t * t % m * a % m;
    else return t * t % m;
}

int main() {
    ull a, b, m;
    cin >> a >> b >> m;
    cout << qpow(a, b, m) << endl;
    return 0;
}


