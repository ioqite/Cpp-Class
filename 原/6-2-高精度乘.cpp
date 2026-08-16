#include<iostream>
#include <string>
using namespace std;

string sx,sy;
int a[10005];
int b[10005];
int c[100000005];

string multi(string sx, string sy) {
	// 1.逆序
	int lenx = sx.size();
	for (int i=0; i<lenx; i++) {
		a[i] = sx[lenx-i-1]-'0';
	}
	int leny = sy.size();
	for (int i=0; i<leny; i++) {
		b[i] = sy[leny-i-1]-'0';
	}

	// 2.相乘
	int len = lenx + leny - 1;
	for (int i = 0; i<lenx; i++){
		for (int j = 0; j<leny; j++){
			c[i+j] = c[i+j] + a[i]*b[j];
			c[i+j+1] += c[i+j]/10;
			c[i+j] =c[i+j]%10;
		}
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

	cout<<multi(sx,sy)<<endl;

	return 0;
}