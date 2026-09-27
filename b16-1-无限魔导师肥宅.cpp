#include <iostream>
#include <algorithm> // 引入 max 函数所需的头文件
using namespace std;

#define MAXN 1024
int n, v, w;
int f1[MAXN]; // f1[i]: 第i点花费，价值是 f1[i] (旧技能表)
int f2[MAXN]; // f2: 新技能表

int main() {
    // 输入基础数据
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> f1[i];
    }

    // 输入新技能的代价(v)和伤害/价值(w)
    cin >> v >> w;

    // 动态规划过程
    for (int j = 0; j <= n; j++) {
        f2[j] = f1[j]; // 1. 原样继承旧技能表的数据

        // 2. 尝试使用新技能进行更新
        // 逻辑：如果当前花费 j 足够支付新技能代价 v，
        // 且 j-v 的状态是合法的（!= -1），则尝试更新最大值
        if (j - v >= 0 && f2[j - v] != -1) {
            f2[j] = max(f2[j], f2[j - v] + w);
        }
    }

    // 输出结果
    for (int i = 1; i <= n; i++) {
        cout << f2[i] << " "; // 添加空格以便阅读
    }

    return 0;
}

