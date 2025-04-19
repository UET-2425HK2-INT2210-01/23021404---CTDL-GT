#include <iostream>
#include <vector>

// H�m ph�n ho?ch Lomuto cho QuickSort
// Ph��ng ph�p n�y ch?n ph?n t? cu?i c�ng l�m pivot v� s?p x?p c�c ph?n t?
// sao cho t?t c? ph?n t? nh? h�n pivot n?m b�n tr�i v� l?n h�n n?m b�n ph?i
int lomutoPartition(std::vector<double>& arr, int low, int high) {
    // Ch?n ph?n t? cu?i c�ng l�m pivot (�?c tr�ng c?a ph�n ho?ch Lomuto)
    double pivot = arr[high];
    
    // Ch? s? c?a ph?n t? cu?i c�ng nh? h�n pivot
    int i = low - 1;
    
    // Duy?t t?t c? c�c ph?n t? v� so s�nh v?i pivot
    for (int j = low; j < high; j++) {
        // N?u ph?n t? hi?n t?i nh? h�n ho?c b?ng pivot
        if (arr[j] <= pivot) {
            // T�ng ch? s? v� ho�n �?i ph?n t?
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    
    // �?t pivot v�o ��ng v? tr� cu?i c�ng c?a d?y c�c ph?n t? nh? h�n n�
    std::swap(arr[i + 1], arr[high]);
    
    // Tr? v? v? tr� c?a pivot
    return i + 1;
}

// H�m QuickSort s? d?ng ph�n ho?ch Lomuto
void quickSort(std::vector<double>& arr, int low, int high) {
    // �i?u ki?n d?ng �? quy
    if (low < high) {
        // L?y ch? s? c?a pivot sau khi ph�n ho?ch
        int pivotIndex = lomutoPartition(arr, low, high);
        
        // �? quy s?p x?p c�c ph?n t? tr�?c pivot
        quickSort(arr, low, pivotIndex - 1);
        
        // �? quy s?p x?p c�c ph?n t? sau pivot
        quickSort(arr, pivotIndex + 1, high);
    }
}

int main() {
    // �?c s? l�?ng ph?n t? n
    int n;
    std::cin >> n;
    
    // Kh?i t?o vector l�u tr? n s? th?c
    std::vector<double> numbers(n);
    
    // �?c n s? th?c t? input
    for (int i = 0; i < n; i++) {
        std::cin >> numbers[i];
    }
    
    // S?p x?p m?ng b?ng QuickSort v?i ph�n ho?ch Lomuto
    quickSort(numbers, 0, n - 1);
    
    // In ra c�c s? �? ��?c s?p x?p
    for (int i = 0; i < n; i++) {
        std::cout << numbers[i];
        // Th�m kho?ng tr?ng gi?a c�c s? (tr? s? cu?i c�ng)
        if (i < n - 1) {
            std::cout << " ";
        }
    }
    
    return 0;
}
