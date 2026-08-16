#include <iostream>
#include <queue>
#include <stdint.h>
using namespace std;

int n;
bool mp[1010][1010]; // 有墙？ 1 有，0 无
bool vis[1010][1010]; // 访问过？
int ans = 0; // 最短路径长度
int8_t dx[] = { -1,  0,  1, -1,  1, -1,  0,  1 };
int8_t dy[] = { -1, -1, -1,  0,  0,  1,  1,  1 };
queue<int> qx, qy, qt;

void bfs(int s) {
    vis[1][1] = 1;
    qx.push(1);
    qy.push(1);
    qt.push(0);
    
    while (!qx.empty()) {
        int x = qx.front(); qx.pop(); // 获取当前点坐标
        int y = qy.front(); qy.pop();
        int t = qt.front(); qt.pop(); // 获取当前点的路径长度
        if (x == n && y == n) { 
            ans = t;
            return; // 找到终点直接结束
        }

        for (int i = 0; i < 8; i++) {
            int tx = x + dx[i];
            int ty = y + dy[i];
            if (tx >= 1 && tx <= n && ty >= 1 && ty <= n 
                  && mp[tx][ty] == 0 && !vis[tx][ty]) {

                vis[tx][ty] = 1;
                qx.push(tx);
                qy.push(ty);
                qt.push(t + 1);
            }
        }
    }
}

int main() {
    cin >> n;
    char tmp;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cin >> tmp;
            mp[i][j] = tmp - '0';
        }
    }

    bfs(1);
    cout << ans << endl;
    return 0;
}

