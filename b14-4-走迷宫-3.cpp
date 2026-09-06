#include <iostream>
using namespace std;

int n, m;
int a[1005][1005];
int dp[1005][1005];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
        }
    }

    // cout << endl << "dp dump:" << endl;
    for (int i = 1; i <= n; ++i) { // 从上往下推
        for (int j = 1; j <= m; ++j) { // 这一步都从 上两步中的最大一点 走过来
            dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]) + a[i][j];
    //         cout << dp[i][j] << " ";
        }
    //     cout << endl;
    }
    
    cout << dp[n][m] << endl;
    return 0;
}

