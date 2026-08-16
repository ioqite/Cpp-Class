#include <iostream>
#include <stack>
#include <string>
using namespace std;

stack<int> s;
int n, num;
string q;

int main() {
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> q;
        if (q == "push") {
            cin >> num;
            s.push(num);
        } else if (q == "pop") {
            if (!s.empty()) s.pop();
        } else if (q == "top") {
            if (s.empty()) cout << "empty" << endl;
            else cout << s.top() << endl;
        } else if (q == "size") {
            cout << s.size() << endl;
        } else if (q == "empty") {
            if (s.empty()) cout << "empty" << endl;
        }
    }
    return 0;
}