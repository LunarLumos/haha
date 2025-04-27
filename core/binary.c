#include <stdio.h>

int main() {
    int arr[] = {11, 12, 22, 25, 64};
    int n = 5, key = 22, low = 0, high = n - 1, mid;

    while (low <= high) {
        mid = (low + high) / 2;
        if (arr[mid] == key) {
            printf("Element found at index %d\n", mid);
            return 0;
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    
    printf("Element not found\n");
    return 0;
}
