#include <iostream>
#include <algorithm>
using namespace std;

int cost[1010];
int value[1010];
int f[1010][2010]; // f[i][j]: 前i个技能，消耗j点魔法时，造成的最大伤害
int n, V;

int main() {
    cin >> n >> V;

    for (int i = 1; i <= n; i++) {
        cin >> value[i] >> cost[i];
    }

    // 初始化：消耗0魔法伤害为0，其余状态非法
    f[0][0] = 0;
    for (int j = 1; j <= V; j++) f[0][j] = -1;

    // 0/1背包 DP
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= V; j++) {
            f[i][j] = f[i - 1][j]; // 不选技能i
            if (j >= cost[i] && f[i - 1][j - cost[i]] != -1) { // 选技能i
                f[i][j] = max(f[i][j], f[i - 1][j - cost[i]] + value[i]);
            }
        }
    }

    cout << f[n][V] << " ";
    
    return 0;
}

