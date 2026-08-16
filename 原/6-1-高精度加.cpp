#include<iostream>
#include <string>
using namespace std;

string sx,sy;
int a[100005];
int b[100005];
int c[100005];

string add(string sx, string sy) {
	// 1.逆序
	int lenx = sx.size();
	for (int i=0; i<lenx; i++) {
		a[i] = sx[lenx-i-1]-'0';
	}
	int leny = sy.size();
	for (int i=0; i<leny; i++) {
		b[i] = sy[leny-i-1]-'0';
	}

	// 2.相加
	int len = max(lenx,leny);
	for (int i = 0;i<len;i++){
		c[i] = c[i]+b[i]+a[i];
		c[i+1] += c[i]/10;
		c[i] = c[i]%10;
	}

	// 3.进位
	if (c[len]) len++;

	//4.逆序转为字符串
	string ans = "";
	for (int i=0; i<len; i++){
		ans = ans + char(c[len-i-1] +'0');
	}
	return ans;
}

int main(){
	cin >> sx >> sy;

	cout<<add(sx,sy)<<endl;

	return 0;
}