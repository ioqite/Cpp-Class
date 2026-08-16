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
        if (q == "buy") {
            cin >> num;
            s.push(num);
        } else if (q == "feed") {
            if (!s.empty()) {
                cout << s.top() << endl;
                s.pop();
            }
            else cout << "zaofanle" << endl;
        }
    }
    return 0;
}
