#include<iostream>
using namespace std;

int cnt[100005];
int n = 0, s, maxn = 0;

int main(){
    cin>>n;
    for (int i=1; i<=n; i++) {
        cin>>s;
        if (s%2==1) {
            cnt[s]++;
            if (s>maxn) maxn = s;
        }
    }
    
    for (int i=0; i<=maxn; i++){
        for (int j=0; j<cnt[i]; j++){
            cout<<i<<" ";
        }
    }

    return 0;
}