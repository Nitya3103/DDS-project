

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
    int top;
    unsigned capacity;
    char *array;
} Stack;

Stack *createStack(unsigned capacity)
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (char *)malloc(stack->capacity * sizeof(char));
    return stack;
}

bool isFull(Stack *stack)
{
    return stack->top == stack->capacity - 1;
}

bool isEmpty(Stack *stack)
{
    return stack->top == -1;
}

void push(Stack *stack, char item)
{
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
}

char pop(Stack *stack)
{
    if (isEmpty(stack))
        return '\0';
    return stack->array[stack->top--];
}

char peek(Stack *stack)
{
    if (isEmpty(stack))
        return '\0';
    return stack->array[stack->top];
}

int precedence(char op1, char op2)
{
    if (op1 == '(' || op2 == ')')
        return 0;
    if (op1 == '+' || op1 == '-')
        return 1;
    if (op1 == '*' || op1 == '/')
        return 2;
    return -1;
}

void convertInfixToPostfix(char *exp)
{

    Stack *stack = createStack(strlen(exp));
    int i, j;
    for (i = 0, j = 0; exp[i] != '\0'; i++)
    {

        if (exp[i] >= 'a' && exp[i] <= 'z' || exp[i] >= 'A' && exp[i] <= 'Z')
            exp[j++] = exp[i];

        else if (exp[i] == '(')
            push(stack, exp[i]);

        else if (exp[i] == ')')
        {
            while (!isEmpty(stack) && peek(stack) != '(')
                exp[j++] = pop(stack);
            if (!isEmpty(stack) && peek(stack) != '(')
                return;
            else
                pop(stack);
        }

        else
        {
            while (!isEmpty(stack) && precedence(exp[i], peek(stack)) <= 0)
                exp[j++] = pop(stack);
            push(stack, exp[i]);
        }
    }

    while (!isEmpty(stack))
        exp[j++] = pop(stack);

    exp[j] = '\0';
    printf("%s", exp);
}

int main()
{
    char expression[] = "((a+(b*c))-d)";
    convertInfixToPostfix(expression);
    return 0;
}
