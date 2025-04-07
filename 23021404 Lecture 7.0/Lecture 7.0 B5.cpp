#include <iostream> 

using namespace std;

int demso(int n) {
	if ( n < 10) return 1;
	return 1 + demso (n/10);
}

int main() {
	int n; cin >> n;
	cout << demso(n);
	return 0;
}
