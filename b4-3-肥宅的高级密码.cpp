#include <iostream>
#include <array>
using namespace std;

int MAX_W;
#define MAX_NUM 4

array<int, 104> a;

void p(int c) { // c: 当前递归位数
    if (c == MAX_W + 1) {
        for (int i=1; i<=MAX_W; i++) {
            cout << a[i];
        }
        cout << endl;
        return;
    }
    for (int i=1; i <= MAX_NUM; i++) {
        if (c > 1 && a[c-1] == i) continue;
        a[c] = i; // 当前位 填数
        p(c + 1); // 进入 下一位
        a[c] = 0; // 当前位 归零
    }
}

int main() {
    cin >> MAX_W;
    p(1);
    return 0;
}
