#include <iostream>
#include <array>
using namespace std;

int n, ans = 0;
array<int, 104> each_money;
array<int, 104> c;

void p(int x) { // x: 当前递归位数
    if (x == n + 1) {
        ans = 0;
        for (int i=1; i<=n; i++) {
            cout << c[i] << " ";
            ans += each_money[i] * c[i];
        }
        cout << ans << endl;
        return;
    }
    for (int i=0; i <= 1; i++) {
        c[x] = i;
        p(x + 1);
    }
}

int main() {
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> each_money[i];
    }
    p(1);
    return 0;
}
