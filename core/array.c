#include <stdio.h>

int main() {
    int arr[10] = {11, 22, 33, 44, 55};
    int n = 5, pos, value;

    printf("Enter position and value to insert:\n");
    scanf("%d %d", &pos, &value);

    for (int i = n; i >= pos; i--) 
        arr[i] = arr[i - 1];
    arr[pos - 1] = value;
    n++;

    printf("Array after insertion:\n");
    for (int i = 0; i < n; i++) 
        printf("%d ", arr[i]);
    printf("\n");

    printf("Enter position to delete:\n");
    scanf("%d", &pos);

    for (int i = pos - 1; i < n - 1; i++) 
        arr[i] = arr[i + 1];
    n--;

    printf("Array after deletion:\n");
    for (int i = 0; i < n; i++) 
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
