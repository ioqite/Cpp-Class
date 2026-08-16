#include <iostream>
#include <queue>
// #include <string>
using namespace std;

queue<int> ms, mr;
int m, n, k;

int main() {
    cin >> m >> n >> k;
    for (int i = 1; i <= m; i++) mr.push(i);
    for (int i = 1; i <= n; i++) ms.push(i);
    for (int i = 1; i <= k; i++) {
        int a = mr.front();
        int b = ms.front();
        cout<<a<<" "<<b<<endl;
        mr.pop();ms.pop();
        mr.push(a);ms.push(b);
    }
    return 0;
}
