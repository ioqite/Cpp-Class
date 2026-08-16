#include <iostream>
#include <array>
using namespace std;

int MAX_W, MAX_NUM, ans = 0;

array<int, 104> a;
array<int, 104> flag;
// int a[104];
// int flag[104];

void p(int c) { // c: 当前递归位数
    if (c == MAX_W + 1) {
        for (int i=1; i<=MAX_W; i++) {
            if (a[i] == i) return;
        }
        ans++;
        return;
    }
    for (int i=1; i <= MAX_NUM; i++) {
        if (flag[i]) continue;
        flag[i] = 1;
        a[c] = i;
        p(c + 1);
        flag[i] = 0;
    }
}

int main() {
    cin >> MAX_W;
    MAX_NUM = MAX_W;
    p(1);
    cout << ans << endl;
    return 0;
}
