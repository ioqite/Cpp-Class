#include <iostream>
using namespace std;

typedef signed char int8_t;

int n, m, tx, ty, start_x = -1, start_y = -1, ans = 0;
bool mp[1010][1010]; // 有水？ 1 有，0 无
bool vis[1010][1010];
int8_t dx[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int8_t dy[] = {-1, -1, -1, 0, 0, 1, 1, 1};

void dfs(int x, int y) {
    for (int i=0; i<8; i++) {
        tx = x + dx[i];
        ty = y + dy[i];
        if (tx >= 1 && tx <= n && ty >= 1 && ty <= m 
              && mp[tx][ty] == 1 && vis[tx][ty] == 0) {
            vis[tx][ty] = 1; // 标记当前节点为已访问
            dfs(tx, ty);
        }
    }
    return;
}

int main() {
    char tmp;
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            cin >> tmp;
            mp[i][j] = (tmp == 'W' ? 1 : 0);
            if (tmp == 'W' && start_x == -1 && start_y == -1) {
                vis[i][j] = 1; // 标记起点为已访问
                start_x = i;
                start_y = j;
                continue;
            }
        }
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            if (mp[i][j] == 1 && vis[i][j] == 0) {
                ans++;
                dfs(i, j);
            }
        }
    }
    cout << ans << endl;
    return 0;
}

