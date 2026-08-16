#include <iostream>
#include <queue>
using namespace std;

int n;
int start_x = -1, start_y = -1, end_x = -1, end_y = -1;
char tmp;

bool mp[1010][1010];  // 有墙? 1 有，0 无
bool vis[1010][1010]; // 访问过?
int ans = -1; // 最短路径长度
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
queue<int> qx, qy, qt;

void bfs() {
    vis[start_x][start_y] = 1;
    qx.push(start_x);
    qy.push(start_y);
    qt.push(0);
    
    while (!qx.empty()) {
        int x = qx.front(); qx.pop(); // 获取当前点坐标
        int y = qy.front(); qy.pop();
        int t = qt.front(); qt.pop(); // 获取当前点的路径长度
        if (x == end_x && y == end_y) { 
            ans = t;
            return; // 找到终点直接结束
        }

        for (int i = 0; i < 4; i++) {
            int tx = x + dx[i];
            int ty = y + dy[i];
            
            // 当前高度 >= 下一格高度、是否访问过
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
    
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cin >> tmp;
            mp[i][j] = (tmp == '1' ? 1 : 0);
            if (tmp == '2') {
                if (start_x == -1) {
                    vis[i][j] = 1; // 标记起点为已访问
                    start_x = i;
                    start_y = j;
                }
                end_x = i;
                end_y = j;
            }
        }
    }

    bfs();
    
    if (ans == -1) {
        cout << -1 << endl;
    } else cout << (ans + 1) / 2 << endl;
    return 0;
}
