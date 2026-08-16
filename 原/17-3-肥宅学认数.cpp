#include <iostream>
#include <queue>
// #include <string>
using namespace std;

queue<int> q;
int m, n, ans = 0, a[10005];
bool cnt[1005];

int main() {
    cin >> m >>n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        int num = a[i];
        if (cnt[num]) continue;
        ans++;
        cnt[num] = 1;
        q.push(num);
        if (q.size() > m) {
            cnt[q.front()] = 0;
            q.pop();
        }
    }
    cout << ans << endl;
    
    return 0;
}