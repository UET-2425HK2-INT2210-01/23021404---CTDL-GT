#include <iostream>
#include <vector>

// Hàm phân ho?ch Lomuto cho QuickSort
// Phýõng pháp này ch?n ph?n t? cu?i cùng làm pivot và s?p x?p các ph?n t?
// sao cho t?t c? ph?n t? nh? hõn pivot n?m bên trái và l?n hõn n?m bên ph?i
int lomutoPartition(std::vector<double>& arr, int low, int high) {
    // Ch?n ph?n t? cu?i cùng làm pivot (ð?c trýng c?a phân ho?ch Lomuto)
    double pivot = arr[high];
    
    // Ch? s? c?a ph?n t? cu?i cùng nh? hõn pivot
    int i = low - 1;
    
    // Duy?t t?t c? các ph?n t? và so sánh v?i pivot
    for (int j = low; j < high; j++) {
        // N?u ph?n t? hi?n t?i nh? hõn ho?c b?ng pivot
        if (arr[j] <= pivot) {
            // Tãng ch? s? và hoán ð?i ph?n t?
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    
    // Ð?t pivot vào ðúng v? trí cu?i cùng c?a d?y các ph?n t? nh? hõn nó
    std::swap(arr[i + 1], arr[high]);
    
    // Tr? v? v? trí c?a pivot
    return i + 1;
}

// Hàm QuickSort s? d?ng phân ho?ch Lomuto
void quickSort(std::vector<double>& arr, int low, int high) {
    // Ði?u ki?n d?ng ð? quy
    if (low < high) {
        // L?y ch? s? c?a pivot sau khi phân ho?ch
        int pivotIndex = lomutoPartition(arr, low, high);
        
        // Ð? quy s?p x?p các ph?n t? trý?c pivot
        quickSort(arr, low, pivotIndex - 1);
        
        // Ð? quy s?p x?p các ph?n t? sau pivot
        quickSort(arr, pivotIndex + 1, high);
    }
}

int main() {
    // Ð?c s? lý?ng ph?n t? n
    int n;
    std::cin >> n;
    
    // Kh?i t?o vector lýu tr? n s? th?c
    std::vector<double> numbers(n);
    
    // Ð?c n s? th?c t? input
    for (int i = 0; i < n; i++) {
        std::cin >> numbers[i];
    }
    
    // S?p x?p m?ng b?ng QuickSort v?i phân ho?ch Lomuto
    quickSort(numbers, 0, n - 1);
    
    // In ra các s? ð? ðý?c s?p x?p
    for (int i = 0; i < n; i++) {
        std::cout << numbers[i];
        // Thêm kho?ng tr?ng gi?a các s? (tr? s? cu?i cùng)
        if (i < n - 1) {
            std::cout << " ";
        }
    }
    
    return 0;
}
