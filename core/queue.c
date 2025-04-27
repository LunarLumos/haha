#include<stdio.h>
#define CAPACITY 3

int queue[CAPACITY];
int front = 0, rear = 0;

void enqueue(int x){
    if(rear < CAPACITY){
        queue[rear] = x;
        rear++;
    } else {
        printf("Queue is full!\n");
    }
}

int dequeue(){
    if(front < rear){
        int val = queue[front];
        front++;
        return val;
    } else {
        printf("Queue is empty!\n");
        return -1;
    }
}

void print(){
    if(front == rear) {
        printf("Queue is empty!\n");
    } else {
        printf("Queue elements: ");
        for(int i = front; i < rear; i++){
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main(){
    enqueue(10);
    enqueue(20);
    enqueue(30);
    print();

    dequeue();
    print();

    enqueue(40);
    print();
}
