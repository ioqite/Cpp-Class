#include<iostream>
using namespace std;
int n;
int ans = 0;
int main(){
    cin >> n;
    for(int a=0; a<=100/3; a++){
        for(int b=0; b<=100; b++){
            for(int c=0; c<=100*3; c=c+3){
                if(a+b+c==n && a*3+b+c/3==100){
                    ans++;
                }
            }
        }
    }
    cout << ans << "\n";
    return 0;
}