#include <iostream>
using namespace std;

typedef signed char int8_t;

int n, m, t, start_x, start_y, end_x, end_y, ans = 0;
bool mp[1010][1010]; // 有障碍？ 1 有，0 无
bool vis[1010][1010];
int8_t dx[4] = {0, 1, 0, -1};
int8_t dy[4] = {1, 0, -1, 0};

void dfs(int x, int y) {
    if (x == end_x && y == end_y) {
        ans++;
        return;
    }
    for (int i = 0; i < 4; i++) {
        int tx = x + dx[i];
        int ty = y + dy[i];
        if (tx >= 1 && tx <= n && ty >= 1 && ty <= m 
              && mp[tx][ty] == 0 && vis[tx][ty] == 0) {
            vis[tx][ty] = 1; // 标记当前节点为已访问
            dfs(tx, ty);
            vis[tx][ty] = 0; // 回溯
        }
    }
    return;
}

int main() {
    int tmp_a, tmp_b;
    cin >> n >> m >> t;
    cin >> start_x >> start_y >> end_x >> end_y;
    for (int i = 1; i <= t; i++) {
        cin >> tmp_a >> tmp_b;
        mp[tmp_a][tmp_b] = 1;
    }
    
    vis[start_x][start_y] = 1; // 在DFS前标记起点已访问
    dfs(start_x, start_y);
    
    cout << ans << endl;
    return 0;
}
