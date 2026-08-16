#include <iostream>
using namespace std;

int n, m, t, a, b, x, ans;
bool mp[1010][1010];

int main() {
    cin >> n >> m >> t;
    for (int i=1; i<=m; i++) {
        cin >> a >> b;
        mp[a][b] = 1;
        mp[b][a] = 1;
    }
    while (t--) {
        cin >> x;
        ans = 0;
        for (int i=1; i<=n; i++) {
            if (mp[x][i] == 1) {
                cout << i << " ";
            }
        }
        cout << endl;
    }
    return 0;
}

