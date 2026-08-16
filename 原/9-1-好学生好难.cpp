#include<iostream>
using namespace std;

int n, m, x, t = 0, cnt=0;
struct se {
    int s;
    int e;
};
se a[1003];

void my_sort() {
    int len = n;
    for (int j = 1; j < len; j++) {
        se key = a[j];
        int i = j - 1;
        while (i >= 0 && a[i].e > key.e) {
            a[i + 1] = a[i];
            i--;
        }
        a[i + 1] = key;
    }
}

int main() {
    cin >> n >> m;
    
    for (int i=0; i<n; i++) {
        cin >> a[i].s >> a[i].e;
    }
    my_sort();
    
    while(m--) {
        t = 0;
        cnt = 0;
        cin >> x;
        for(int j=0; j<n; j++) {
            if (a[j].s > t) {
                cnt++;
                t = a[j].e;
            }
            if (x == cnt) {
                cout << t << endl;
                break;
            }
        }
    }
    
    return 0;
}
