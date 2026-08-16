#include <iostream>
using namespace std;

typedef signed char int8_t;

int n, m, tx, ty;
char tmp;
bool mp[1010][1010]; // 有墙？ 1 不可走，0 可走
bool vis[1010][1010];
int8_t dx[4] = {0, 1, 0, -1};
int8_t dy[4] = {1, 0, -1, 0};

void dfs(int x, int y) {
    if (tx == n && ty == m) {
        return;
    }
    for (int i=0; i<4; i++) {
        tx = x + dx[i];
        ty = y + dy[i];
        if (tx >= 1 && tx <= n && ty >= 1 && ty <= m 
              && mp[tx][ty] == 0 && vis[tx][ty] == 0) {
            vis[tx][ty] = 1; // 标记当前节点为已访问
            dfs(tx, ty);
        }
    }
    return;
}

int main() {
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            cin >> tmp;
            mp[i][j] = (tmp == '#' ? 1 : 0);
        }
    }
    vis[1][1] = 1; // 标记起点为已访问
    dfs(1, 1);
    cout << (vis[n][m] ? "YES" : "NO") << endl;
    return 0;
}

