#include <iostream>
#include <string>

using namespace std;

int m, x, mi = 2e9;
string op;

int main(){
    cin >> m;
    while (m--){
        cin >> op;
        if (op == "add") {
            cin >> x;
            if (mi > x) mi = x;
        }
        else if (op == "min") {
            cout << mi << endl;
        }
    }
    return 0;
}
