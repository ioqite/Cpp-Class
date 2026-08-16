#include <iostream>
using namespace std;

unsigned int x, y;

unsigned int next_num(unsigned int x, unsigned int y) {
    if (y == 0) return x;
    return next_num(y, x % y);
}

int main() {
    cin >> x >> y;
    cout << next_num(x, y) << endl;
    return 0;
}
