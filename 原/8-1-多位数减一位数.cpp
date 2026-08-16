#include<iostream>
#include <string>
using namespace std;

string sx,sy;
int a[100005];
int b[100005];
int c[100005];

int compare(string sx, string sy) {
	// 1.逆序
	int lenx = sx.size();
	int leny = sy.size();
	// 2.比长度
	if (lenx>leny) return 1;
	if (lenx<leny) return -1;
	// 3.比
	if (sx<sy) return -1;
	if (sx>sy) return 1;
	
	return 0;
}

string sub_one(string sx, string sy) {
	string ans = "";
	int cmp = compare(sx,sy);
	if (cmp == -1) {
		swap(sx, sy);
		ans = "-";
	}
	if (cmp == 0) {
		ans = "0";
		cout << ans << endl;
		return 0;
	}

	// 1.逆序
	int lenx = sx.size();
	int leny = sy.size();
	for (int i=0; i<lenx; i++) a[i] = sx[lenx-i-1]-'0';
	for (int i=0; i<leny; i++) b[i] = sy[leny-i-1]-'0';
	
	int len = lenx;

	// 2.相减
	for (int i = 0; i<lenx; i++){
		c[i] = c[i]+a[i]-b[i];
		if (c[i] < 0) {
			c[i] += 10;
			c[i+1]--;
		}
	}

	//3.逆序转为字符串
	for (int i=0; i<len; i++){
		ans = ans + char(c[len-i-1] +'0');
	}
	return ans;
}

int main(){
	cin >> sx >> sy;

	cout<<sub_one(sx,sy)<<endl;

	return 0;
}