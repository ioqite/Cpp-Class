#include <iostream>
#include <algorithm>
using namespace std;

int cost[1010];
int value[1010];
int f[1010][2010]; // f[i][j]: 前i个物品，花费j元时的最大美味值
int n, V;

int main() {
    cin >> n >> V;

    for (int i = 1; i <= n; i++) {
        cin >> value[i] >> cost[i];
    }

    f[0][0] = 0; // 初始化状态，花费0元时的最大美味值为0
     // 花费0元时的最大美味值为0
    for (int i = 1; i <= V; i++) f[0][i] = -1;
    
    // 0/1背包 DP - 所有状态初始化为0
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= V; j++) {
            f[i][j] = f[i - 1][j]; // 不选第i个物品
            if (j >= cost[i] && f[i][j - cost[i]] != -1) { // 选第i个物品
                f[i][j] = max(f[i][j], f[i][j - cost[i]] + value[i]);
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= V; i++) {
        ans = max(ans, f[n][i]);
    }
    cout << ans;

    return 0;
}

