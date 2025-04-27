#include<stdio.h>

int main(){
    int x;
    x=10;
    int *ptr;
    ptr=&x;

    printf("print the value of x: %d\n",*ptr);
    printf("Print the address of x: %p\n",ptr);
}