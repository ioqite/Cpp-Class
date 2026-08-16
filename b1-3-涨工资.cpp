#include <iostream>
#include <vector>
using namespace std;

vector<unsigned int> v = {1, 3, 5};
unsigned int n;

void next_month() {
    if (v.size() < n) {
        v.push_back(v[v.size()-1] + v[v.size()-3]);
        next_month();
    } else {
        cout << v[n-1] << endl;
    }
}

int main() {
    cin >> n;
    next_month();
    return 0;
}
