#include <iostream>
#include <queue>
#include <stdint.h>
using namespace std;

int n, m, start_pos, end_pos, tmp_a, tmp_b;
char tmp;

bool mp[1010][1010];  // 可传播? 1 可，0 不可
bool vis[1010]; // 是否传递过?
int ans = -1; // 最短路径长度
queue<int> q, qt;

void bfs() {
    q.push(start_pos);
    qt.push(0);
    vis[start_pos] = 1;
    while (!q.empty()) {
        int x = q.front(); q.pop(); // 获取当前点坐标
        int t = qt.front(); qt.pop(); // 获取当前点的路径长度
        if (x == end_pos) {
            ans = t;
            break;
        }
        for (int i=1; i<=n; i++) {
            // 下一格是否可传播、是否访问过
            if (mp[x][i] == 1 && vis[i] == 0) {
                vis[i] = 1;
                q.push(i);
                qt.push(t + 1);
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> tmp_a >> tmp_b;
        mp[tmp_a][tmp_b] = 1;
        mp[tmp_b][tmp_a] = 1;
    }
    cin >> start_pos >> end_pos;

    bfs();
    
    cout << ans << endl;
    return 0;
}
