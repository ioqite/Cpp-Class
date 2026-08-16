#include<iostream>
using namespace std;

unsigned long long a, b, m, t1 = 1;

int main() {
    cin >> a >> b >> m;
    a %= m;
    for(unsigned int i=0; i<b; i++) {
        t1 *= a;
        t1 %= m;
    }
    cout << t1 << endl;
    return 0;
}
