#include <iostream>

using namespace std;

int tich(int n) {
	if(n == 1) return 1;
	return n * tich(n - 1);
} 

int main() {
	int n;
	cin >> n;
	cout << tich(n);
	return 0;
}
