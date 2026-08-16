#include <iostream>
#include <queue>
using namespace std;

int n, m;
int start_x, start_y, end_x, end_y;
bool flag = 0; // 是否找到路径

int mp[1010][1010]; 
bool vis[1010][1010]; 

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
queue<int> qx, qy;

void bfs() {
    vis[start_x][start_y] = 1;
    qx.push(start_x);
    qy.push(start_y);
    
    while (!qx.empty()) {
        int x = qx.front(); qx.pop();
        int y = qy.front(); qy.pop();
        if (x == end_x && y == end_y) { 
            flag = 1; 
            return; // 找到终点直接结束
        }

        for (int i = 0; i < 4; i++) {
            int tx = x + dx[i];
            int ty = y + dy[i];
            
            // 当前高度 >= 下一格高度、是否访问过
            if (tx >= 1 && tx <= n && ty >= 1 && ty <= m 
                  && mp[x][y] >= mp[tx][ty] && !vis[tx][ty]) {

                vis[tx][ty] = 1;
                qx.push(tx);
                qy.push(ty);
            }
        }
    }
}

int main() {
    cin >> n >> m;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> mp[i][j];
        }
    }
        
    cin >> start_x >> start_y >> end_x >> end_y;

    bfs();
    
    cout << (flag ? "yes" : "no") << endl;
    return 0;
}
