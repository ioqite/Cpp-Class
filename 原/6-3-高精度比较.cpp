#include<iostream>
#include <string>
using namespace std;

string sx,sy;
int a[10005];
int b[10005];

char compare(string sx, string sy) {
	// 1.逆序
	int lenx = sx.size();
	int leny = sy.size();

	// 2.比长度
	if (lenx>leny) return '>';
	if (lenx<leny) return '<';

	// 3.逐位比
	for (int i = 0; i<lenx; i++){
		if (sx[i]<sy[i]) return '<';
		if (sx[i]>sy[i]) return '>';
	}
	return '=';
}

int main(){
	cin >> sx >> sy;
	cout << compare(sx,sy);
	return 0;
}