#include <iostream>
#include <queue>
#include <string>
using namespace std;

queue<int> q;
int n, num;
string s;

int main() {
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> s;
        if (s == "push") {
            cin >> num;
            q.push(num);
        } else if (s == "pop") {
            if (!q.empty()) q.pop();
        } else if (s == "front") {
            if (q.empty()) cout << "empty" << endl;
            else cout << q.front() << endl;
        } else if (s == "size") {
            cout << q.size() << endl;
        } else if (s == "back") {
            if (q.empty()) cout << "empty" << endl;
            else cout << q.back() << endl;
        }
    }
    return 0;
}