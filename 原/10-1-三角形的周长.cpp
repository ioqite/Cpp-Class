#include<iostream>
#include <algorithm>

using namespace std;

int n, t, len = 0, a[1000005];

int main() {
    cin >> n;
    
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    sort(a, a+n);
    
    for(int i=0; i<n; i++) {
        if (a[n-2-i] + a[n-3-i] > a[n-1-i]) {
            len += a[n-2-i] + a[n-3-i] + a[n-1-i];
            break;
        }
    }
    
    cout << len << endl;
    return 0;
}