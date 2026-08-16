#include<iostream>

using namespace std;

int a[10] = {6,2,5,5,4,5,6,3,7,6};

int main(){
    int n, cnt=0;
    cin >> n;
    n -= 4;
    for(int i=0; i<=9; i++){
        for(int j=0; (i+j)<=9; j++){
            if(a[i] + a[j] + a[i+j] == n) cnt++;
        }
    }
    cout << cnt;
    return 0;
}