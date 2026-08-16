#include <iostream>
#include <algorithm>
using namespace std;

int a[100005], x, n, q, l, r, mid, ans = 0;

int main() {
    cin >> n;
    cin >> q;
    for (int i=1; i<=n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);

    while (q--) {
        cin >> x;
        l = 1;
        r = n;
        ans = 0;
        while (l <= r) {
            mid = (l + r) / 2;
            if (a[mid] > x) {
                r = mid - 1; // 往小找
            }
            else if (a[mid] < x) {
                ans = a[mid];
                l = mid + 1; // 往大找
            }
            else if (a[mid] == x) {
                r = mid - 1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
