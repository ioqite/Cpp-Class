#include <iostream>
#include <array>
using namespace std;

int MAX_W;
#define MAX_NUM 3

int ans = 0;

array<int, 104> a;

void p(int c) {
    if (c == MAX_W + 1) {
        ans++;
        return;
    }
    for (int i=1; i <= MAX_NUM; i++){
        a[c] = i;
        p(c + 1);
        a[c] = 0;
    }
}

int main() {
    cin >> MAX_W;
    p(1);
    cout << ans;
    return 0;
}
