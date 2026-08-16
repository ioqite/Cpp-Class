#include <iostream>
#include <string>
using namespace std;

int a[100005], n, k;

bool cheak(int mid){
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        cnt += a[i] / mid;
    }
    return cnt >= k;
}

int main() {
    cin >> n >> k;
    int mx = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        mx = max(mx, a[i]);
    }
    int l = 1, r = mx, ans = 0;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (cheak(mid)) {
            l = mid + 1;
            ans = mid;
        } else {
            r = mid - 1;
        }
    }
    cout << ans << endl;
    return 0;
}
