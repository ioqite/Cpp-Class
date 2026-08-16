//选择排序-从小到大
#include<iostream>

using namespace std;

int a[1005];
int n, t;

int main(){
    cin>>n;
    for (int i=1; i<=n; i++) cin>>a[i];
    
    for (int i=1;i<n;i++){
        t = 1;
        for (int j=t+1;j<=n-i+1;j++){
            if (a[j]>a[t]) t = j;
        }
        swap(a[t],a[n-i+1]);
    }

    for (int i=1; i<=n; i++) cout<<a[i]<<" ";
    
    return 0;
}