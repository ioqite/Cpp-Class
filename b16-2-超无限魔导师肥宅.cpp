#include <iostream>
#include <algorithm>
using namespace std;

int cost[55];
int value[55];
int f[55][1010]; // f[i][j]: 前i个物品，花费j元时的最大美味值
int n, V;

int main() {
    cin >> n >> V;

    for (int i = 1; i <= n; i++) {
        cin >> cost[i] >> value[i];
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

    for (int i = 1; i <= V; i++) cout << f[n][i] << " ";
    
    return 0;
}

