//插入排序-从小到大
#include<iostream>

using namespace std;

int a[1005];
int n = 0, h;

int main(){
    cin>>n;
    for (int i=1; i<=n; i++) cin>>a[i];
    
    for (int i=2; i<=n; i++){
        for (int j=i; j>1; j--){
            if (a[j]<a[j-1]) {
                swap(a[j],a[j-1]);
            } else {
                break;
            };
        }
    }

    for (int i=1; i<=n; i++) cout<<a[i]<<" ";

    return 0;
}