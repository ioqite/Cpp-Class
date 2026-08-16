#include <iostream>
#include <cmath>
using namespace std;

int n, ans = 0;

int main() {
    cin >> n;
    n *= 1000;
    while (pow(2, ans) < n) {
        ans++;
    }
    cout << ans << endl;
    return 0;
}
