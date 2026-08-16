#include <iostream>
#include <algorithm>
using namespace std;

typedef signed char int8_t;

int n, ans = -1e9;
int mp[1010][1010]; // 有障碍？ 1 有，0 无
volatile bool vis[1010][1010];
int8_t dx[4] = {0, 1, 0, -1};
int8_t dy[4] = {1, 0, -1, 0};

void dfs(int x, int y, int sum) {
    // cout << "x: " << x << ", y: " << y << ", sum: " << sum << endl;
    if (x == n && y == n) {
        // cout << "[END] ans: " << ans << ", sum: " << sum << endl;
        ans = max(sum, ans);
        return;
    }
    for (int i=0; i<4; i++) {
        int tx = x + dx[i];
        int ty = y + dy[i];
        if (tx >= 1 && tx <= n && ty >= 1 && ty <= n && vis[tx][ty] == 0) {
            vis[tx][ty] = 1; // 标记当前节点为已访问
            dfs(tx, ty, sum + mp[tx][ty]);
            vis[tx][ty] = 0; // 回溯
            // cout << "[Back] x: " << x << ", y: " << y << ", sum: " << sum << endl;
        }
    }
    return;
}

int main() {
    cin >> n;
    for (int i=1; i<=n; i++) 
        for (int j=1; j<=n; j++) 
            cin >> mp[i][j];

    vis[1][1] = 1;
    dfs(1, 1, mp[1][1]);
    cout << ans << endl;
    return 0;
}

