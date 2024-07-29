#include <stdio.h>
#include <string.h>
#define MAX 100

char stack[MAX], input[MAX];
int top = -1, j = 0;

void push(char c) {
    stack[++top] = c;
}

void pop() {
    top--;
}

void display() {
    int i;
    for (i = 0; i <= top; i++) {
        printf("%c", stack[i]);
    }
    printf("\t%s\n", input + j);
}

int main() {
    printf("Mohan Thapa Masharangi\n");
    printf("Shift Reduce Parser\n");
    printf("Enter the input string: ");
    scanf("%s", input);
    printf("STACK\tINPUT\n");
    while (1) {
        if (input[j] != '\0') {
            push(input[j]);
            input[j] = ' ';
            j++;
            printf("Shift\t");
            display();
        }

        if (top >= 2 && stack[top] == 'a' && stack[top - 1] == 'a' && stack[top - 2] == 'a') {
            stack[top - 2] = 'A';
            top -= 2;
            printf("Reduce by A -> aaa\t");
            display();
        } else if (top >= 2 && stack[top] == 'b' && stack[top - 1] == 'b' && stack[top - 2] == 'A') {
            stack[top - 2] = 'S';
            top -= 2;
            printf("Reduce by S -> Abb\t");
            display();
        } else if (top >= 1 && stack[top] == 'a' && stack[top - 1] == 'a') {
            stack[top - 1] = 'B';
            top--;
            printf("Reduce by B -> aa\t");
            display();
        } else if (input[j] == '\0') {
            break;
        }
    }

    if (top == 0 && stack[top] == 'S' && input[j] == '\0') {
        printf("Accepted\n");
    } else {
        printf("Rejected\n");
    }
    return 0;
}
