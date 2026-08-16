#include <iostream>
#include <stack>
#include <string>
using namespace std;

stack<char> st;
string s;

int main() {
    cin >> s;
    int len = s.size();
    for (int i = 0; i < len; i++) {
        if (s[i] == '(') {
            st.push('(');
        } else if (s[i] == ')') {
            if (!st.empty()) st.pop();
            else {
                cout << "NO";
                return 0;
            }
        }
    }
    if (st.empty()) cout << "YES";
    else cout << "NO";
    return 0;
}