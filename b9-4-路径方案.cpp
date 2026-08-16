#include <iostream>
using namespace std;

int n;
int maze[10][10]; // 存储迷宫地图
bool vis[10][10];  // 标记是否访问过
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
long long ans = 0; // 方案数可能很大，使用 long long 防止溢出

void dfs(int x, int y) {
    // 如果到达终点（3），方案数加1并返回
    if (maze[x][y] == 3) {
        ans++;
        return;
    }
    
    // 遍历四个方向
    for (int i = 0; i < 4; i++) {
        int tx = x + dx[i];
        int ty = y + dy[i];
        
        // 判断边界、是否是墙（1）以及是否已经走过
        if (tx >= 0 && tx < n && ty >= 0 && ty < n && maze[tx][ty] != 1 && !vis[tx][ty]) {
            vis[tx][ty] = 1; // 标记当前点已访问
            dfs(tx, ty);    // 继续搜索
            vis[tx][ty] = 0; // 回溯，撤销标记
        }
    }
}

int main() {
    int start_x = 0, start_y = 0;
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> maze[i][j];
            // 记录起点坐标
            if (maze[i][j] == 2) {
                start_x = i;
                start_y = j;
            }
        }
    }
    
    // 标记起点为已访问
    vis[start_x][start_y] = 1;
    // 从起点开始深搜
    dfs(start_x, start_y);
    
    cout << ans << endl;
    return 0;
}

