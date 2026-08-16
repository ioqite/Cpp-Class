#include<iostream>
#include <string>
using namespace std;

string sx,sy;
int a[100005];
int b;
int c[100005];
string ans = "";
int shang, yu=0;

int compare(string sx, string sy) {
	// 1.长度
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

string div(string s1, int b){
	int cmp = compare(sx,sy);
	if (cmp == -1) {
		cout << "0" << sx << endl;
		return 0;
	}
	if (cmp == 0) {
		cout << "1" << "0" << endl;
		return 0;
	}
	
	int len = s1.size();
	int f = 0;
	for (int i = 0; i < len; i++) {
		yu = yu * 10 + (s1[i] - '0');
		int shang = yu / b;
		if (shang != 0) {
			f = 1;
		}
		if (f==1) ans += char(shang+'0');
		yu %= b;
	}
	if (ans == "") ans = "0";
	return ans;
}

int main(){
	cin >> sx >> b;

	cout << div(sx, b) << " " << yu << endl;

	return 0;
}