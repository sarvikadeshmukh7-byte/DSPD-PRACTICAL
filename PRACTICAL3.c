#include <stdio.h>
#include <string.h>

#define MAX 50
char queue[MAX];
int front = -1;
int rear = -1;

void enq(char ch) {
    if (rear == MAX - 1) {
        printf("Overflow!\n");
    } else {
        if (front == -1)
            front = 0;
        rear = rear + 1;
        queue[rear] = ch;
    }
}

void deq() {
    if (front == -1 || front > rear) {
        printf("Underflow!\n");
        front = rear = -1;
    } else {
        printf("Dequeued element: %c\n", queue[front]);
        front = front + 1;
    }
}

void display() {
    if (front == -1) {
        printf("Queue is Empty\n");
    } else {
        printf("Queue: ");
        for (int i = front; i <= rear; i++) {
            printf("%c ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    char ch;
    int c;

    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &c);

        switch (c) {
            case 1:
                printf("Enter value: ");
                scanf(" %c", &ch);
                enq(ch);
                break;

            case 2:
                deq();
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid Choice!\n");
        }
    }
}
