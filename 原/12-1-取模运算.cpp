#include<iostream>
using namespace std;

unsigned long long n, a, b = 1000000007;

int main() {
    cin >> n >> a;
    cout << ((a%b) * (n%b)) % b << endl;
    return 0;
}
