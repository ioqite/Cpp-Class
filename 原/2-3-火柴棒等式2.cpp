#include<iostream>

using namespace std;

int a[10] = {6,2,5,5,4,5,6,3,7,6};
int c = 0, sum1, sum2, sum3, z;

int f(int x, int y) {
    z = x+y;
    c = 0;
    sum1 = 0, sum2 = 0, sum3 = 0;
    if (x==0) {
        c += a[x];
    }else{
        while(x > 0){
            int t = x % 10;
            sum1 += a[t];
            x /= 10;
        }
        c += sum1;
    }
    if (y==0) {
        c += a[y];
    }else{
        while(y > 0){
            int t = y % 10;
            sum2 += a[t];
            y /= 10;
        }
        c += sum2;
    }
    if (z==0) {
        c += a[z];
    }else{
        while(z > 0){
            int t = z % 10;
            sum3 += a[t];
            z /= 10;
        }
        c += sum3;
    }
    return c;
}

int main(){
    int n, cnt=0;
    cin >> n;
    n -= 4;
    for(int i=0; i<=2000; i++){
        for(int j=i; j<=2000; j++){
            if(f(i, j) == n) cnt++;
        }
    }
    cout << cnt;
    return 0;
}