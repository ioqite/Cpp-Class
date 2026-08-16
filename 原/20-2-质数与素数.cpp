#include <iostream>
#include <cmath>
using namespace std;

int n, a[105], b[105];

bool is_prime(int x) {
    if (x <= 1) return 0;
    for (int i=2; i*i<=x; i++) {
        if (x % i == 0) return 0;
    }
    return 1;
}

int main() {
    cin >> n;
    for (int i=0; i<n; i++) cin >> a[i];
    for (int i=0; i<n; i++) cin >> b[i];

    for (int i=0; i<n; i++) cout << (is_prime(a[i]) ? 'y' : 'n');
    cout << endl;
    for (int i=0; i<n; i++) cout << (is_prime(b[i]) ? 'y' : 'n');
    cout << endl;
    for (int i=0; i<n; i++) cout << (is_prime(a[i] - b[i]) ? 'y' : 'n');
    cout << endl;
    for (int i=0; i<n; i++) cout << (is_prime(a[i] + b[i]) ? 'y' : 'n');
    cout << endl;

    return 0;
}
