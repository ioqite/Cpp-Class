#include <iostream>
#include <queue>
#include <stdint.h>
using namespace std;

int n, m;
char tmp;

bool mp[1010][1010];  // 可流水? 1 可，0 不可
bool vis[1010][1010]; // 是否有水?
int ans = -1; // 最短路径长度
int8_t dx[] = { -1,  0,  1, -1,  1, -1,  0,  1 };
int8_t dy[] = { -1, -1, -1,  0,  0,  1,  1,  1 };
queue<int> qx, qy, qt;

void bfs() {
    while (!qx.empty()) {
        int x = qx.front(); qx.pop(); // 获取当前点坐标
        int y = qy.front(); qy.pop();
        int t = qt.front(); qt.pop(); // 获取当前点的路径长度
        ans = max(ans, t);
        for (int i = 0; i < 8; i++) {
            int tx = x + dx[i];
            int ty = y + dy[i];
            
            // 下一格是否在范围内、是否是墙、是否访问过
            if (tx >= 1 && tx <= n && ty >= 1 && ty <= m 
                  && mp[tx][ty] == 1 && !vis[tx][ty]) {

                vis[tx][ty] = 1;
                qx.push(tx);
                qy.push(ty);
                qt.push(t + 1);
            }
        }
    }
}

int main() {
    cin >> n >> m;
    
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            cin >> tmp;
            mp[i][j] = (tmp == '0' ? 1 : 0);
            if (tmp == '2') {
                qx.push(i);
                qy.push(j);
                qt.push(0);
                vis[i][j] = 1;
            }
        }
    }

    bfs();
    
    cout << ans << endl;
    return 0;
}
