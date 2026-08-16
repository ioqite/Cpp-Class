#include <iostream>
using namespace std;

int n, m, t, a, b, x, ans_i, ans_o;
int mp[1010][1010];

int main() {
    cin >> n >> m >> t;
    for (int i=1; i<=m; i++) {
        cin >> a >> b;
        mp[a][b] = 1;
    }
    while (t--) {
        cin >> x;
        ans_i = 0;
        ans_o = 0;
        for (int i=1; i<=n; i++) {
            if (mp[x][i] == 1) {
                ans_i++;
            }
            if (mp[i][x] == 1) {
                ans_o++;
            }
        }
        cout << ans_i << " " << ans_o << endl;
    }
    return 0;
}

