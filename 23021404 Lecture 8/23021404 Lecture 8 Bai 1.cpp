#include <iostream>
#include <vector>

// Hàm partition cho thuật toán QuickSort
// Chọn phần tử pivot và đặt nó vào đúng vị trí, các phần tử nhỏ hơn pivot nằm bên trái, lớn hơn nằm bên phải
int partition(std::vector<double>& arr, int low, int high) {
    // Chọn phần tử cuối cùng làm pivot
    double pivot = arr[high];
    // Chỉ số của phần tử nhỏ hơn
    int i = low - 1;

    // Duyệt từng phần tử của mảng
    for (int j = low; j < high; j++) {
        // Nếu phần tử hiện tại nhỏ hơn hoặc bằng pivot
        if (arr[j] <= pivot) {
            // Tăng chỉ số i và hoán đổi arr[i] với arr[j]
            i++;
            std::swap(arr[i], arr[j]);
        }
    }

    // Đặt pivot vào đúng vị trí của nó
    std::swap(arr[i + 1], arr[high]);
    // Trả về vị trí của pivot
    return i + 1;
}

// Hàm QuickSort
// Sắp xếp mảng arr từ chỉ số low đến high
void quickSort(std::vector<double>& arr, int low, int high) {
    // Điều kiện dừng đệ quy: low >= high
    if (low < high) {
        // Lấy vị trí của pivot sau khi phân hoạch
        int pivotIndex = partition(arr, low, high);

        // Đệ quy sắp xếp các phần tử bên trái pivot
        quickSort(arr, low, pivotIndex - 1);
        // Đệ quy sắp xếp các phần tử bên phải pivot
        quickSort(arr, pivotIndex + 1, high);
    }
}

int main() {
    // Đọc số lượng phần tử n
    int n;
    std::cin >> n;

    // Tạo vector để lưu n số thực
    std::vector<double> numbers(n);

    // Đọc n số thực từ input
    for (int i = 0; i < n; i++) {
        std::cin >> numbers[i];
    }

    // Gọi hàm quickSort để sắp xếp mảng
    quickSort(numbers, 0, n - 1);

    // In ra các số đã được sắp xếp
    for (int i = 0; i < n; i++) {
        std::cout << numbers[i];
        // In khoảng trắng giữa các số, trừ số cuối cùng
        if (i < n - 1) {
            std::cout << " ";
        }
    }

    return 0;
}
