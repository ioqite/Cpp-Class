#include <iostream>
#include <cstring>
using namespace std;

int t, n;
long long dp[100010];

int main() {
    cin >> t;
    while (t--) {
        cin >> n;

        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        for (int i = 1; i <= n; ++i) { // 从下往上推
            // 这一步都从上两步中的走过来
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        
        cout << dp[n] << endl;
    }
    return 0;
}

