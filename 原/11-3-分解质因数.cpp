#include<iostream>
using namespace std;

int n;

void print_FIPF(int un) {
	int first = 1;
	cout << n << "=";
	for (int i=2; i<=n; i++) {
		while (n % i == 0) {
			if (first == 1) {
				cout << i;
				first = 0;
			} else {
				cout << "*" << i;
			}
			n /= i;
		}
	}
	if (n != 1) cout << n << endl;
}

int main() {
	cin >> n;
	print_FIPF(n);

	return 0;
}