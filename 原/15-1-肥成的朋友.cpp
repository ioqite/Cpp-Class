#include <iostream>
#include <algorithm>
using namespace std;

int a[100005], n, q, x, y, l, r, mid, ansl, ansr;

int main() {
    cin >> n >> q;
    for (int i=1; i<=n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);

    while (q--) {
        cin >> x >> y;
        l = 1;
        r = n;
        ansl = 0;
        while (l <= r) {
            mid = (l + r) / 2;
            if (a[mid] >= x) {
                ansl = mid;
                r = mid - 1; // 往小找
            }
            else {
                l = mid + 1; // 往大找
            }
        }
        l = 1;
        r = n;
        ansr = n + 1;
        while (l <= r) {
            mid = (l + r) / 2;
            if (a[mid] <= y) {
                ansr = mid;
                l = mid + 1; // 往小找
            } else {
                r = mid - 1; // 往大找
            }
        }
        cout << ansr - ansl + 1 << endl;
    }
    return 0;
}
