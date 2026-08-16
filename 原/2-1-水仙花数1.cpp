#include<iostream>
#include<cmath>

using namespace std;

int isArmstrong(int n);

int main(){
    int n;
    cin >> n;
    
    if(isArmstrong(n)){
        cout << "YES" << "\n";
    }
    else{
        cout << "NO" << "\n";
    }
    return 0;
}

int isArmstrong(int n){
    int n2 = n, n3 = n, w = 0, cnt = 0;
    while (n2>0)
    {
        w++;
        n2/=10;
    }

    for(int i=0; i<=w; i++){
        cnt += pow((n3%10), w);
        n3/=10;
    }

    return cnt==n;
}