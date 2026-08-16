#include<iostream>
using namespace std;

unsigned long long a, b, m, ans = 1, m_pow = 2;

int main() {
    cin >> a >> b >> m;
    a %= m;
    m_pow = a;
    while(b) {
        if(b & 1) ans = (ans * m_pow) % m;
        m_pow *= m_pow;
        m_pow %= m;
        b >>= 1;
    }
    cout << ans << endl;
    return 0;
}
