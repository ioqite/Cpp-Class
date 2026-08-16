#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int num[10005], a, N, _n;

void Ans(int a, int N){
    num[1] = a;
    int i = 1, cnt, j = 2;
    for (cnt = 1; cnt <= N; i++) {
        if (num[i] == num[i-1]) continue;
        num[j++] = 2 * num[i] + 1;
        num[j++] = 3 * num[i] + 1;
        sort(num+i, num+j);
        cnt++;
    }
    cout << num[--i] << endl;
}

int main() {
    cin >> _n;
    for (int i = 0; i < _n; i++) {
        cin >> a >> N;
        Ans(a, N);
    }
    return 0;
}