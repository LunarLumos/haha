#include<stdio.h>

int main(){
    int arr1[] = {1, 2, 3};
    int arr2[] = {4, 5, 6};
    int size1 = 3, size2 = 3;
    int merged[size1 + size2];
    

    for(int i = 0; i < size1; i++){
        merged[i] = arr1[i];
    }
    for(int i = 0; i < size2; i++){
        merged[size1 + i] = arr2[i];
    }

    for(int i = 0; i < size1 + size2; i++){
        printf("%d ", merged[i]);
    }
    printf("\n");

    return 0;
}
