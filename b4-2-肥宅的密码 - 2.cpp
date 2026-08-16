#include <iostream>
#include <array>
using namespace std;

#define MAX_W 10
#define MAX_NUM 3

array<int, 104> a;

void p(int c) {
    if (c == MAX_W + 1) {
        for (int i=1; i<=MAX_W; i++){
            cout << a[i];
        }
        cout << endl;
        return;
    }
    for (int i=1; i <= MAX_NUM; i++){
        a[c] = i;
        p(c + 1);
        a[c] = 0;
    }
}

int main() {
    p(1);
    return 0;
}
