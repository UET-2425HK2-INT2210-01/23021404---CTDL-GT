#include <iostream>

using namespace std;

int lt(int x, int n) {
	if (n == 0) return 1;
	return x * lt(x, n - 1);
}

int main() {
	int x, n;
	cin >> x >> n;
	cout << lt(x, n);
	return 0;
}
