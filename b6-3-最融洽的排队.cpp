#include <iostream>
#include <array>
#include <algorithm>
using namespace std;

int ans_num = 0, n, current_ans_num;
array<int, 104> each_num;
array<int, 104> each_sel;
array<int, 104> each_lock;
array<int, 104> ans_queue;

void p(int x) { // x: 第x 的编号选择
    if (x == n + 1) {
        current_ans_num = 0;
        for (int i=1; i<n; i++) {
            current_ans_num += __gcd(each_num[each_sel[i]], each_num[each_sel[i+1]]);
        }
        if (current_ans_num > ans_num) {
            ans_num = max(ans_num, current_ans_num);
            ans_queue = each_sel;
        }
        return;
    }
    for (int i=1; i <= n; i++) {
        if (each_lock[i]) continue;
        each_lock[i] = 1;
        each_sel[x] = i;
        p(x + 1);
        each_lock[i] = 0;
    }
}

int main() {
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> each_num[i];
    }
    p(1);
    cout << ans_num << endl;
    for (int i=1; i<=n; i++) {
        cout << ans_queue[i] << " ";
    }
    return 0;
}
