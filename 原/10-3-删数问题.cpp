#include <iostream>
#include <string>
using namespace std;

int k;
bool flag = 0;
string s, ans = "";

int main() {
	cin >> s;
	cin >> k;

	for(int i=1; i <= k; i++){ //刪除k次
		string t = "";
		flag = 0;
		for(int j = 0;j<s.size()-1; j++){//每次删除一个数
			if (s[j] <= s[j+1] || flag == 1) {
				t += s[j];
			} else flag = 1; //s[j] > s[j+1] 第一个比右边大的删除}
		}
		if(flag == 1) t += s[s.size() - 1];//前面删除过了,最后一个要加
		s = t;
	}
	flag = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] =='0') {
			if (flag == 1) {
				ans += s[i];
			}
		} else {
			flag = 1;
			ans += s[i];
		}
	}

	if (ans == "") ans = "0";
	cout << ans << endl;
	return 0;
}