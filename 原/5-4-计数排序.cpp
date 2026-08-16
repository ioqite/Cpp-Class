//计数排序-从小到大
#include<iostream>

using namespace std;

int cnt[705];
int n = 0, s;

int main(){
    cin>>n;
    for (int i=1; i<=n; i++) {
        cin>>s;
        cnt[s]++;
    }
    
    for (int i=0; i<=666; i++){
        for (int j=0; j<cnt[i]; j++){
            cout<<i<<" ";
        }
    }

    return 0;
}