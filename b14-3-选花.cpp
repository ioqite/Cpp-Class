#include <iostream>
using namespace std;

#define MAXN 1005

int n;
int a[MAXN];
int f[MAXN][2]; // f[i][1] 表示选择第i盆花时，能够得到的最大价值
                // f[i][0] 表示不选择第i盆花时，能够得到的最大价值

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    f[1][1] = a[1];
    f[1][0] = 0;
    for (int i = 2; i <= n; i++) {
        f[i][1] = f[i-1][0] + a[i];
        f[i][0] = max(f[i-1][0], f[i-1][1]);
    }

    cout << max(f[n][1], f[n][0]) << endl;
    return 0;
}

