#include <iostream>
using namespace std;

int a[100005], x, n, q, l, r, mid;
bool found = 0;

int main() {
    cin >> n;
    for (int i=1; i<=n; i++) cin >> a[i];
    cin >> q;
    while (q--) {
        cin >> x;
        l = 1;
        r = n;
        found = 0;
        while (l <= r && !found) {
            mid = (l + r) / 2;
            if (a[mid] > x) r = mid - 1; // 往小找
            else if (a[mid] < x) l = mid + 1; // 往大找
            else if (a[mid] == x) found = 1;
        }
        if (found) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}
