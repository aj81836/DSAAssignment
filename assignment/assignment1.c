#include <stdio.h>
#include<stdlib.h>

int linearSearch(int arr[], int n, int find);

int main() {
    int arr[] = {5, 2, 4, 6, 1, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int find= 4;

    int result = linearSearch(arr, n, find);
    if (result != -1) {
        printf("Element %d at index %d\n", find, result);
    } else {
        printf("Element %d not found in the arr\n", find);
    }

    return 0;
}

int linearSearch(int arr[], int n, int find) {
    
    if (n == 0) {
        return -1;
    }
    
    
    if (arr[n - 1] == find) {
        return n - 1; 
    }
    
    return linearSearch(arr, n - 1, find);
}

