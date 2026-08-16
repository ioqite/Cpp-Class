#include<iostream>

using namespace std;

int a[1005];
int n, cnt_swap = 0;
long long cnt_money = 0;

int main(){
    cin>>n;
    for (int i=1; i<=n; i++) cin>>a[i];
    
    for (int i=1; i<n; i++){
        for (int j=1; j<=n-i; j++){
            if (a[j]>a[j+1]) {
                swap(a[j],a[j+1]);
                cnt_money += ++cnt_swap;
            }
        }
    }

    cout<<cnt_money<<endl;
    
    return 0;
}