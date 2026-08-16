#include <iostream>
using namespace std;

unsigned long long n, ans = 1;

void n_m(unsigned long long o) {
    if (!o) return;
    ans *= o;
    n_m(o-1);
}

int main() {
    cin >> n;
    n_m(n);
    cout << ans << endl;
    return 0;
}
