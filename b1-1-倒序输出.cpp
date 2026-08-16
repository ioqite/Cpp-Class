#include <iostream>
#include <string>
using namespace std;

string n;

void reverse_print(int pos) {
    if (pos < 0) return;
    cout << n[pos];
    reverse_print(pos-1);
}

int main() {
    cin >> n;
    reverse_print(n.size()-1);

    return 0;
}
