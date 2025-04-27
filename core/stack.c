#include<stdio.h>
#define CAPACITY 3

int stack[CAPACITY];
int top = -1;

void push(int x){
    if(top < CAPACITY - 1){
        top++;
        stack[top] = x;
    } else {
        printf("No space!\n");
    }
}

int pop(){
    if(top >= 0){
        int val = stack[top];
        top--;
        return val;
    } else {
        printf("Stack is empty!\n");
        return -1;
    }
}

void print(){
    if (top == -1) {
        printf("Stack is empty!\n");
    } else {
        printf("Stack elements: ");
        for(int i = 0; i <= top; i++){
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main(){
    push(10);
    push(20);
    push(30);
    print();

    pop();
    print();

    push(40);
    print();
}
