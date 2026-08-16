#include <iostream>
#include <array>
using namespace std;

int MAX_W, tmp;
#define MAX_NUM 5

array<int, 104> a;

void p(int c) {
    if (c == MAX_W + 1) {
        tmp = 0;
        for (int i=1; i<=MAX_W; i++) {
            tmp += a[i];
        }
        if (tmp%2 == 1) return;

        for (int i=1; i<=MAX_W; i++) {
            cout << a[i];
        }
        cout << endl;
        return;
    }
    for (int i=1; i <= MAX_NUM; i++) {
        a[c] = i;
        p(c + 1);
        a[c] = 0;
    }
}

int main() {
    cin >> MAX_W;
    p(1);
    return 0;
}
