#include <iostream>
using namespace std;

int a[100005], n, k, t, y, cnt, sum, maxn, l, r, mid, ans;

bool check(int x) {
    cnt = 1;
    sum = 0;
    for (int i=1; i<=n; i++) {
        if (sum + a[i] > x) {
            cnt++;
            sum = 0;
        }
        sum += a[i];
    }
    return cnt <= k;
}

int main() {
    cin >> n >> k;
    sum = 0;
    maxn = 0;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        sum += a[i];
        maxn = max(maxn, a[i]);
    }

    l = maxn;
    r = sum;
    while (l <= r) {
        mid = (l + r) / 2;
        if (check(mid)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << ans << endl;
    return 0;
}
