#include <iostream>
using namespace std;

int n, ans;
int a[100010];
int dp[100010];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; ++i) {
        dp[i] = (dp[i-1]>0 ? dp[i-1] : 0) + a[i];
        ans = max(ans, dp[i]);
    }
    
    cout << (ans>0 ? ans : 0) << endl;
    return 0;
}

