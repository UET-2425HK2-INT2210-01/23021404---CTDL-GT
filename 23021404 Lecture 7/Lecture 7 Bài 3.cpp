#include <iostream>

using namespace std;

// Hàm đệ quy tìm GCD sử dụng thuật toán Euclid
int gcd(int x, int y) {
    if (y == 0) return x;
    return gcd(y, x % y);
}

int main() {
    int x, y;
    cin >> x >> y;
    cout << gcd(x, y) << endl;
    return 0;
}
