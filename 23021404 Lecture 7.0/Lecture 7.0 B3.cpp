#include <iostream> 

using namespace std;

int Fi(int n) {
	if (n == 0) return 0;
	if (n == 1 || n <= 2) return 1;
	return Fi(n-1) + Fi(n-2);
}

int main() {
	int n;
	cin >> n;
	cout << Fi(n);
}
