#include <iostream>
using namespace std;

int dem(int n) {
    if (n < 10) return 1;
    return 1 + dem(n / 10);
}

int mu10(int k) {
    if (k == 0) return 1;
    return 10 * mu10(k - 1);
}


int daonguoc(int dem, int n) {
    if (n < 10) return n;
    int bien = mu10(dem - 1); 
    return (n % 10) * bien + daonguoc(dem - 1, n / 10);
}

int main() {
    int n;
    cin >> n;
    int biendem = dem(n);
    cout << daonguoc(biendem, n);
    return 0;
}

