#include <iostream>
#include <array>
using namespace std;

#define MAX_NUM 4

int n, ans;
array<int, 11> v;
array<int, 104> a; // 每只猫的奖项

void p(int c) { // c: 当前递归位数
    if (c == n + 1) { // 可能位数
        ans = 0;
        for (int i=1; i<=n; i++) {
            ans += v[a[i]];
            cout << a[i] << " ";
        }
        cout << ans << endl;
        
        return;
    }
    for (int i=1; i <= MAX_NUM; i++) {
        a[c] = i; // 当前位 填数
        p(c + 1); // 进入 下一位
    }
}

int main() {
    cin >> n;
    for (int i=1; i<=4; i++) cin >> v[i];
    p(1);
    return 0;
}
