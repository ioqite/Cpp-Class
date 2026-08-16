#include<iostream>
using namespace std;

int n, a[10002];

void count_FIPF(int _n) {
    for (int i=2; i<=_n; i++) {
        while (_n % i == 0) {
            a[i]++;
            _n /= i;
        }
    }
    if (_n != 1) a[_n]++;
}

int main() {
    cin >> n;
    for (int i=n; i>0; i--) {
        count_FIPF(i);
    }
    for (int i=2; i<=n; i++) {
        if (a[i]) {
            cout << i << " " << a[i] << endl;
        }
    }
    return 0;
}
