#include <iostream>

using namespace std;

void print_array(int arr[], int size) {
    cout << "[ ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << ']';
}

enum sort_direction { ASCENDING, DESCENDING };

bool should_swap(sort_direction dir, int a, int b) {
    return ASCENDING == dir ? a > b : a < b;
}

void bubble_sort_core(sort_direction dir, int arr[], int size) {
    for (int i = 1; i < size; i++) {
        if (should_swap(dir, arr[i - 1], arr[i])) {
            int temp = arr[i];
            arr[i] = arr[i - 1];
            arr[i - 1] = temp;
        }
    }
}

void bubble_sort(int arr[], int size) {
    int iter = size;
    while (iter > 0) {
        bubble_sort_core(ASCENDING, arr, iter);
        iter--;
    }
}

void bubble_sort_descending(int arr[], int size) {
    int iter = size;
    while (iter > 0) {
        bubble_sort_core(DESCENDING, arr, iter);
        iter--;
    }
}

void bubble_sort_recursive(int arr[], int size) {
    if (size <= 1) {
        return;
    }
    bubble_sort_core(ASCENDING, arr, size);
    bubble_sort_recursive(arr, size - 1);
}

void bubble_sort_recursive_descending(int arr[], int size) {
    if (size <= 1) {
        return;
    }
    bubble_sort_core(DESCENDING, arr, size);
    bubble_sort_recursive_descending(arr, size - 1);
}

void execute_bubble_sort(int arr[], int size) {
    print_array(arr, size);
    bubble_sort(arr, size);
    cout << " -> ";
    print_array(arr, size);
    cout << endl;
}

int main() {
    int arr0[] = { };
    int arr1[] = { 1 };
    int arr2[] = { -1, 3, 5 };
    int arr3[] = { 10, 8, 6, 4, -1 };
    int arr4[] = { 6, 6, 6, 6 };
    int arr5[] = { 8, 24, -10, -9, 6, 0 };

    execute_bubble_sort(arr0, 0);
    execute_bubble_sort(arr1, sizeof(arr1) / sizeof(arr1[0]));
    execute_bubble_sort(arr2, sizeof(arr2) / sizeof(arr2[0]));
    execute_bubble_sort(arr3, sizeof(arr3) / sizeof(arr3[0]));
    execute_bubble_sort(arr4, sizeof(arr4) / sizeof(arr4[0]));
    execute_bubble_sort(arr5, sizeof(arr5) / sizeof(arr5[0]));
}