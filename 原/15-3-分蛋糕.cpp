#include <iostream>
#include <algorithm>

using namespace std;

int a[100005];
int n;
long long m;

bool check(int x) {
    if (x == 0) return true;
    long long count = 0;
    for (int i = 0; i < n; ++i) {
        count += a[i] / x;
        if (count >= m) return true;
    }
    return count >= m;
}

int main() {
    cin >> n >> m;

    int maxn = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] > maxn) maxn = a[i];
    }

    int l = 1;
    int r = maxn;
    int ans = 0;

    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (check(mid)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    cout << ans << endl;
    return 0;
}