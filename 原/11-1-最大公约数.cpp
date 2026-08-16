// 0 < a,b <= 10^9
#include<iostream>
using namespace std;

int a, b;

int greatest_common_divisor(int ua, int ub) {
	if (ua == 0 || ub == 0) return 0;
	int t;
	while (ub != 0) {
		t = ua % ub;
		ua = ub;
		ub = t;
	}
	return ua;
}

int main(){
	cin >> a;
	cin >> b;
	
	cout << greatest_common_divisor(a, b)<<endl;

	return 0;
}