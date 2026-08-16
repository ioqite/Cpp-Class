#include<iostream>
#include <algorithm>

using namespace std;

int n, w, zu_cnt=0, t;
int a[30005];

int main() {
    cin >> w;
    cin >> n;
    
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    sort(a, a+n);
    
    for(int i=n-1; i>=0; i--) {
        if (a[i]==0) continue;
        t = a[i];
        a[i] = 0;
        for(int j=i-1;j>=0;j--) {
            if (t+a[j] <= w) {
                t+=a[j];
                a[j] = 0;
            }
            if (t>=w) break;
        
        }
        zu_cnt++;
    }
    
    cout << zu_cnt << endl;
    return 0;
}