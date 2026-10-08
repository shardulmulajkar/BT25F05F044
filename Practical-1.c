#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

typedef struct Stack {
    int arr[MAX];
    int top;
} Stack;

void initStack(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

int isFull(Stack *s) {
    return s->top == MAX - 1;
}

void push(Stack *s, int x) {
    if (isFull(s)) {
        printf("Stack Overflow\n");
        return;
    }
    s->arr[++s->top] = x;
}

int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        return -1;
    }
    return s->arr[s->top--];
}

int evaluatePostfix(char exp[]) {
    Stack s;
    int i, val1, val2;
    initStack(&s);

    for (i = 0; exp[i] != '\0'; i++) {
        if (exp[i] == ' ')
            continue;

        if (isdigit(exp[i])) {
            push(&s, exp[i] - '0');
        }
        else {
            val2 = pop(&s);
            val1 = pop(&s);
            switch (exp[i]) {
                case '+':
                    push(&s, val1 + val2);
                    break;
                case '-':
                    push(&s, val1 - val2);
                    break;
                case '*':
                    push(&s, val1 * val2);
                    break;
                case '/':
                    push(&s, val1 / val2);
                    break;
                case '%':
                    push(&s, val1 % val2);
                    break;
            }
        }
    }
    return pop(&s);
}

int main() {
    char postfix[MAX];

    printf("Enter Postfix Expression: ");
    fgets(postfix, MAX, stdin);
    postfix[strcspn(postfix, "\n")] = '\0';

    printf("Result = %d\n", evaluatePostfix(postfix));

    return 0;
}

