#include<iostream>
using namespace std;
int n = 999;
int main(){
    for(int a=9; a>0; a--){
        for(int b=9; b>=0; b--){
            for(int c=9; c>=0; c--){
                if(a*a*a+b*b*b+c*c*c==n){
                    cout << a << b << c << "\n";
                }
                n--;
            }
        }
    }
    return 0;
}