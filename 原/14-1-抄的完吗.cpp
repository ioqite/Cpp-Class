#include <iostream>
#include <algorithm>
using namespace std;

int a[100005], n, k, t, y, cnt, sum;

bool check(int x) {
    cnt = 1;
    sum = 0;
    for (int i=1; i<=n; i++) {
        if (sum + a[i] <= x) {
            sum += a[i];
        } else {
            cnt++;
            sum = a[i];
        }
    }
    return cnt <= k;
}

int main() {
    cin >> n >> k >> t;
    for (int i=1; i<=n; i++) cin >> a[i];

    while (t--) {
        cin >> y;
        if (check(y)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
