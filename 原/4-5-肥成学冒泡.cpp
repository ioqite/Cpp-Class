#include<iostream>

using namespace std;

int a[10005];
int n, cnt_if = 0, cnt_swap = 0;

int main(){
    cin>>n;
    for (int i=1; i<=n; i++) cin>>a[i];
    
    for (int i=1; i<n; i++){
        for (int j=1; j<=n-i; j++){
            cnt_if++;
            if (a[j]>a[j+1]) {
                swap(a[j],a[j+1]);
                cnt_swap++;
            }
        }
    }

    cout<<cnt_if<<" "<<cnt_swap<<endl;
    
    return 0;
}