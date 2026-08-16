#include <iostream>
#include <cmath>

using namespace std;

void isArmstrong(unsigned long long n);

unsigned long long a, b;
unsigned int w = 0, f = 0;
unsigned long long n2, n3, cnt = 0;

int main(){
    cin >> a >> b;
    for(unsigned long long i=a; i<=b; i++) {
        isArmstrong(i);
    }

    if(!f){
        cout << "NO" << "\n";
    } else{
        cout << "\n";
    }
    return 0;
}

void isArmstrong(unsigned long long n){
    unsigned long long n2 = n, n3 = n, w = 0, cnt = 0;
    while (n2>0)
    {
        w++;
        n2/=10;
    }
    for(int i=0; i<=w; i++){
        cnt += pow((n3%10), w);
        n3/=10;
    }
    if(cnt==n){
        cout << n << " ";
        f = 1;
    }
}
