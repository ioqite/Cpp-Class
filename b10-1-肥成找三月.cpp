#include <iostream>
#include <queue>
using namespace std;

int n, m, tmp_a, tmp_b;
bool mp[1010][1010]; // 有？ 1 有，0 无
bool bj[1010];
queue<int> q;

void bfs(int s) {
    bj[s] = 1;
    q.push(s);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (u == n) break;
        for (int v=1; v<=n; v++) {
            if (mp[u][v] == 1 && bj[v] == 0) {
                bj[v] = 1;
                q.push(v);
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> tmp_a >> tmp_b;
        mp[tmp_a][tmp_b] = 1;
    }

    bfs(1);
    cout << (bj[n] ? "YES" : "NO") << endl;
    return 0;
}

