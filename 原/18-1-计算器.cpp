#include <iostream>
#include <stack>
#include <string>
using namespace std;

stack<char> op;
stack<long long> num;
string s;

int level(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    return 0;
}

long long cal() {
    long long ans = 0;
    long long b = num.top();
    num.pop();
    long long a = num.top();
    num.pop();
    switch(op.top()) {
        case '+': ans = a+b; break;
        case '-': ans = a-b; break;
        case '*': ans = a*b; break;
        case '/': ans = a/b; break;
    }
    op.pop();
    return ans;
}

int main() {
    cin >> s;
    int len = s.size();
    for (int i = 0; i < len; i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            long long ans = 0;
            while (s[i] >= '0' && s[i]<='9') {
                ans = ans * 10 + (s[i]-'0'); i++;
            }
            i--;
            num.push(ans);
        } else if (s[i] == '(') {
            op.push(s[i]);
        } else if (s[i] == ')') {
            while (op.top() != '(') {
                long long ans = cal();
                num.push(ans);
            }
            op.pop();
        } else {
            while (!op.empty() && op.top() != '(' && level(op.top()) >= level(s[i])) {
                long long ans = cal();
                num.push(ans);
            }
            op.push(s[i]);
        }
    }
    while (!op.empty()) {
        long long ans = cal();
        num.push(ans);
    }
    cout << num.top() << endl;
    return 0;
}