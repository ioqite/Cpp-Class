#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int a[2005];
int b[2005];
int c[2005];

int n;

string add(string sx, string sy) {
	memset(a, 0 ,sizeof(a));
	memset(b, 0 ,sizeof(b));
	memset(c, 0 ,sizeof(c));

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

string multi(string sx, string sy) {
	memset(a, 0 ,sizeof(a));
	memset(b, 0 ,sizeof(b));
	memset(c, 0 ,sizeof(c));
	
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

string fibonacci(int n) {
	// 斐波那契
	if (n == 1 || n == 2) return "1";
	string a = "1", b = "1", c;
	for (int i=3;i<=n;i++){
		c = add(a,b);
		a = b;
		b = c;
	}

	return c;
}

int main(){
	cin >> n;
	
	cout<<fibonacci(n)<<endl;

	return 0;
}