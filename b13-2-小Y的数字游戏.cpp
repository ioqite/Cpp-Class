#include <iostream>
using namespace std;

int n, q;
int a[100010];
int dp[100010];

int main() {
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; ++i) {
        dp[i] = dp[i-1] + a[i];
    }
    
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << dp[r] - dp[l-1] << endl;
    }
    return 0;
}

