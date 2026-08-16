#include <iostream>
using namespace std;

typedef signed char int8_t;

int n, m, tx, ty, start_x, start_y, ans = 0;
char tmp;
bool mp[1010][1010]; // 有苹果？ 1 有，0 无
bool vis[1010][1010];
int8_t dx[4] = {0, 1, 0, -1};
int8_t dy[4] = {1, 0, -1, 0};

void dfs(int x, int y) {
    ans++;
    for (int i=0; i<4; i++) {
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
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            cin >> tmp;
            mp[i][j] = (tmp == '#' ? 0 : 1);
            if (tmp == '@') {
                vis[i][j] = 1; // 标记起点为已访问
                start_x = i;
                start_y = j;
            }
        }
    }
    dfs(start_x, start_y);
    cout << ans << endl;
    return 0;
}

