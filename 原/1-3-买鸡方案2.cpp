#include<iostream>
using namespace std;
int n, m, a, b, ans = 0;
int main(){
    cin >> n >> m;
    for(int c=3; c<=m*3; c+=3){
        a = ((m-c/3)-(n-c))/2;
        b = n - a - c;
        if(a>0 && b>0 && a+b+c==n && a*3+b+c/3==m){
            ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}