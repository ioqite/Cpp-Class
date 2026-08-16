#include <iostream>
#include <array>
using namespace std;

int max_weight, n, current_weight, current_money, ans = 0;
array<int, 104> each_money;
array<int, 104> each_weight;
array<int, 104> each;

void p(int x) { // x: 第x 买不买
    if (x == n + 1) {
        current_weight = 0;
        current_money = 0;
        for (int i=1; i<=n; i++) {
            current_weight += each_weight[i] * each[i];
            current_money += each_money[i] * each[i];
        }
        if (current_weight > max_weight) {
            return;
        }
        ans = max(ans, current_money);
        return;
    }
    for (int i=0; i <= 1; i++) {
        each[x] = i;
        p(x + 1);
    }
}

int main() {
    cin >> n >> max_weight;
    for (int i=1; i<=n; i++) {
        cin >> each_weight[i] >> each_money[i];
    }
    p(1);
    cout << ans << endl;
    return 0;
}
