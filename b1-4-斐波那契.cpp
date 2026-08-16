#include <iostream>
#include <vector>
using namespace std;

vector<unsigned int> v = {0, 1};
unsigned int n;

void next_num() {
    if (v.size() <= n) {
        v.push_back(v[v.size()-1] + v[v.size()-2]);
        next_num();
    } else {
        cout << v[n] << endl;
    }
}

int main() {
    cin >> n;
    next_num();
    return 0;
}
