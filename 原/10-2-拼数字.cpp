#include<iostream>

using namespace std;

int n, a[12], pos = 0;

int main() {
    cin >> n;
    
    if (n > 45) {
        cout << -1 << endl;
        return 0;
    } else if (n < 10) {
        cout << n << endl;
        return 0;
    }
    for (int i=9; i>0; i--) {
        if (n <= i) {
            a[pos++] = n;
            for (int j=pos-1; j>=0; j--) {
                cout << a[j];
            }
            cout << endl;
            return 0;
        }
        if (n > i) {
            n -= i;
            a[pos++] = i;
        }
    }
    
    cout << -1 << endl;
    return 0;
}