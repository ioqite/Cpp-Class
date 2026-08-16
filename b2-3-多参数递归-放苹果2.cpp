#include <iostream>
using namespace std;

int f(int a,int b){
    if(a < 0) return 0;
    else if(b == 1) return 1;
    else return f(a, b-1) + f(a-b, b);
}
int main() {    
    int a,b;
    cin >> a >> b;
    cout << f(a, b);
    return 0;
}

