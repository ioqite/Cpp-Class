#include <iostream>
#include <queue>
using namespace std;

int n, m, tmp_a, tmp_b, start_pos, end_pos;
bool mp[1010][1010]; // 有？ 1 有，0 无
bool bj[1010];
queue<int> q;

void bfs(int s) {
    bj[s] = 1;
    q.push(s);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (u == end_pos) break;
        for (int v=1; v<=n; v++) {
            if (mp[u][v] == 1 && bj[v] == 0) {
                bj[v] = 1;
                q.push(v);
            }
        }
    }
}

int main() {
    cin >> n >> m >> start_pos >> end_pos;
    for (int i = 1; i <= m; i++) {
        cin >> tmp_a >> tmp_b;
        mp[tmp_a][tmp_b] = 1;
    }

    bfs(start_pos);
    cout << (bj[end_pos] ? "YES" : "NO") << endl;
    return 0;
}

