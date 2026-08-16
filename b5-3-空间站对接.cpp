#include <iostream>
#include <array>
using namespace std;

#define LOG_I(msg) cout << "[I] " << msg;
// #define LOG_I(msg) do{} while(0);

int n, maxn = 0, sum = 0;

array<int, 104> a;
array<array<int, 104>, 104> wants;
array<int, 104> flag;
array<int, 104> ans;

void p(int c) { // c: 当前递归位数
    if (c == n + 1) {
        sum = 0;
        for (int i=1; i<=n; i++) {
            sum += wants[i][a[i]];
        }
        
        if (sum > maxn) {
            maxn = sum;
            ans = a;
        }
        return;
    }
    for (int i=1; i <= n; i++) {
        if (flag[i]) continue;
        flag[i] = 1;
        a[c] = i;
        p(c + 1);
        flag[i] = 0;
    }
}

int main() {
    cin >> n;
    for (int i=1; i<=n; i++) 
        for (int j=1; j<=n; j++) 
            cin >> wants[i][j];

    p(1);
    cout << maxn << endl;
    for (int i=1; i<=n; i++)
        cout << ans[i] << " ";
    cout << endl;
    return 0;
}
