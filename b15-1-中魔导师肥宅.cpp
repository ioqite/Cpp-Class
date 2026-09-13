#include <iostream>
using namespace std;

int n, v, w;
int f1[1024];
int f2[1024];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> f1[i];
    }
    cin >> v >> w;
    
    for (int i = 0; i <= n; ++i) {
        f2[i] = f1[i];
        if (i >= v && f1[i-v] != -1) f2[i] = max(f2[i], f1[i-v] + w);
    }
    for (int i = 1; i <= n; ++i) {
        cout << f2[i] << " ";
    }
    return 0;
}

