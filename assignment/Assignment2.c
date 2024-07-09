#include <stdio.h>
#include<stdlib.h>

int binarySearch(int arr[], int left, int right, int find );

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int find = 4;

    int result = binarySearch(arr, 0, n - 1, find);
    if (result != -1) {
        printf("Element %d found at index %d\n", find, result);
    } else {
        printf("Element %d not found in the arr\n", find);
    }

    return 0;
}


int binarySearch(int arr[], int left, int right, int find ){
    
    if (left <= right) {
        int mid = left + (right - left) / 2;
        
        
        if (arr[mid] == find) {
            return mid; 
        }
        
        
        if (arr[mid] > find) {
            return binarySearch(arr, left, mid - 1, find);
        }
        
    
        return binarySearch(arr, mid + 1, right, find);
    }
    
    return -1;
}

