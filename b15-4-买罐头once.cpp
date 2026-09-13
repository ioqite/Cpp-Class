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
        cin >> cost[i] >> value[i];
    }

    // 0/1背包 DP - 所有状态初始化为0
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= V; j++) {
            f[i][j] = f[i - 1][j]; // 不选第i个物品
            if (j >= cost[i]) { // 选第i个物品
                f[i][j] = max(f[i][j], f[i - 1][j - cost[i]] + value[i]);
            }
        }
    }

    cout << f[n][V] << endl;
    
    return 0;
}

