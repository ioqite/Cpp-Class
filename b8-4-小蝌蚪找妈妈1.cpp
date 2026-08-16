#include <iostream>
using namespace std;

int n, m, a, b, ans = 0;
bool mp[1010][1010];
bool vis[1010];

void dfs(int cur, int e) {
    ans++;
    for (int i=1; i<=n; i++) {
        if (mp[i][cur] == 1 && vis[i] == 0) {
            vis[i] = 1; // 标记当前节点为已访问
            dfs(i, e);
        }
    }
    return;
}

int main() {
    cin >> n >> m;
    for (int i=1; i<=m; i++) {
        cin >> a >> b;
        mp[a][b] = 1;
        mp[b][a] = 1;
    }
    vis[1] = 1; // 标记起点为已访问
    dfs(1, n);
    cout << (ans>=n ? "no" : "yes") << endl;
    return 0;
}

