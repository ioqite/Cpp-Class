#include <iostream>
#include <stack>
#include <string>
using namespace std;

stack<char> s;
string t, ut;

int main() {
    cin >> t;
    int len = t.size();
    for (int i = 0; i < len; i++) {
        if (t[i] == '#') {
            if (!s.empty()) s.pop();
        } else if (t[i] == '@') {
            while (!s.empty()) s.pop();
        } else {
            s.push(t[i]);
        }
    }
    while (!s.empty()) {
        ut = s.top() + ut;
        s.pop();
    }
    cout << ut << endl;
    return 0;
}