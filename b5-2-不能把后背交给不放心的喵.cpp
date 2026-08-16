#include <iostream>
#include <array>
using namespace std;

#define LOG_I(msg) cout << "[I] " << msg;
// #define LOG_I(msg) do{} while(0);

int n, ans = 0;

array<int, 104> a;
array<int, 104> not_want;
array<int, 104> flag;
// int a[104];
// int not_want[104];
// int flag[104];

void p(int c) { // c: 当前递归位数
    if (c == n + 1) {
        // cout << "[Info] ";
        // for (int i=1; i<=n; i++) {
        //     cout << a[i] << " ";
        // }
        // cout << endl;
        
        for (int i=2; i<=n; i++) {
            if (a[i] == not_want[a[i-1]]) return;
        }

        // cout << "OK" << endl;
        
        ans++;
        return;
    }
    for (int i=1; i <= n; i++) {
        if (flag[i]) continue;
        flag[i] = 1;
        // if (c>1 && not_want[c-1] == i) continue;
        a[c] = i;
        p(c + 1);
        flag[i] = 0;
    }
}

int main() {
    cin >> n;
    for (int i=1; i<=n; i++) cin >> not_want[i];
    p(1);
    cout << ans << endl;
    return 0;
}
