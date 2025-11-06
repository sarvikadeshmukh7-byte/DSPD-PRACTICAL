#include <stdio.h>
#include <string.h>
#define MAX 5

int stack[MAX], top = -1;

void push(int val) {
    if (top == MAX - 1)
        printf("Stack overflow!\n");
    else
        stack[++top] = val;
}

void pop() {
    if (top == -1)
        printf("Stack underflow!\n");
    else
        printf("Popped: %d\n", stack[top--]);
}

void display() {
    if (top == -1)
        printf("Stack is empty!\n");
    else {
        printf("Stack: ");
        for (int i = 0; i <= top; i++)
            printf("%d ", stack[i]);
        printf("\n");
    }
}

void checkPalindrome(char str[]) {
    int len = strlen(str);
    int t = -1;
    char temp[MAX];

    for (int i = 0; i < len; i++)
        temp[++t] = str[i];

    for (int i = 0; i < len; i++) {
        if (str[i] != temp[t--]) {
            printf("%s is not Palindrome\n", str);
            return;
        }
    }
    printf("%s is Palindrome\n", str);
}

int main() {
    int choice, val;
    char str[50];

    do {
        printf("\n1. Push\n2. Pop\n3. Palindrome\n4. Display\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                push(val);
                break;
            case 2:
                pop();
                break;
            case 3:
                printf("Enter string: ");
                scanf("%s", str);
                checkPalindrome(str);
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exit...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 5);

    return 0;
}
