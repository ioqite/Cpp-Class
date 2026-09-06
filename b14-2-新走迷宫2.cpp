#include <iostream>
using namespace std;

int n, m;
int a[13][13];
int dp[13][13];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
        }
    }
    
    for (int i = 1; i <= n; ++i) { // 从上往下推
        for (int j = 1; j <= m; ++j) { // 这一步都从上两步走过来
            if (i == 1 && j == 1) dp[i][j] = 1;
            else {
                if (a[i][j] > a[i][j - 1]) dp[i][j] += dp[i][j - 1];
                if (a[i][j] > a[i - 1][j]) dp[i][j] += dp[i - 1][j];
            }
        }
    }
    
    cout << dp[n][m] << endl;
    return 0;
}

