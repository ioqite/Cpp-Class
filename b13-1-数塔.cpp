#include <iostream>
using namespace std;

int n;
int a[110][110];
int dp[110][110];
int ans;

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            cin >> a[i][j];
        }
    }
    
    for (int i = 1; i <= n; ++i) { // 从上往下推
        for (int j = 1; j <= i; ++j) { // 这一步都从上两步中的最大一点走过来
            dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + a[i][j];
        }
    }
    
    ans = 0;
    for (int i = 1; i <= n; ++i) { // 最后一层走一遍找答案
        ans = max(ans, dp[n][i]);
    }
    
    cout << ans << endl;
    return 0;
}

