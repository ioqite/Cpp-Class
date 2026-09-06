#include <iostream>
using namespace std;

int n, m;
int dp[13][13];

int main() {
    cin >> n >> m;
    
    for (int i = 1; i <= n; ++i) { // 从上往下推
        for (int j = 1; j <= m; ++j) { // 这一步都从上两步中的最大一点走过来
            if (i == 1 && j == 1) dp[i][j] = 1;
            else dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
        }
    }
    
    cout << dp[n][m] << endl;
    return 0;
}

