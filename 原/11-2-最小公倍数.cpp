// a,b in INT
#include<iostream>
using namespace std;

unsigned long long a, b; // u_int64_t

unsigned long long least_common_multiple(unsigned long long ua, unsigned long long ub) {
	unsigned long long avr = ua * ub;
	if (ua == 0 || ub == 0) return 0;
	unsigned long long t;
	while (ub != 0) {
		t = ua % ub;
		ua = ub;
		ub = t;
	}
	return avr / ua;
}

int main() {
	cin >> a;
	cin >> b;
	
	cout << least_common_multiple(a, b)<<endl;

	return 0;
}