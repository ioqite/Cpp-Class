#include <iostream>
#include <queue>
#include <string>
using namespace std;

queue<string> q;
int n;
string s, num;

int main() {
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> s;
        if (s == "I") {
            cin >> num;
            q.push(num);
        } else if (s == "O") {
            if (!q.empty()) {
                cout << q.front() << endl;
                q.pop();
            } else cout << "None" << endl;
        }
    }
    return 0;
}