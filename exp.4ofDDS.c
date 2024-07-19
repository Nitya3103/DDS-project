
#include <stdio.h>
#include <stdlib.h>

struct StackNode
{
    int data;
    struct StackNode *next;
};

struct StackNode *createNode(int data)
{
    struct StackNode *newNode = (struct StackNode *)malloc(sizeof(struct StackNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void push(struct StackNode **top, int data)
{
    struct StackNode *newNode = createNode(data);
    newNode->next = *top;
    *top = newNode;
}

int pop(struct StackNode **top)
{
    if (*top == NULL)
    {
        printf("Stack underflow!\n");
        return -1;
    }
    struct StackNode *temp = *top;
    *top = (*top)->next;
    int popped = temp->data;
    free(temp);
    return popped;
}

void moveDisk(char source, char destination, int disk)
{
    printf("Move disk %d from rod %c to rod %c\n", disk, source, destination);
}

void towerOfHanoi(int numDisks, struct StackNode *source, struct StackNode *aux, struct StackNode *dest)
{
    if (numDisks == 1)
    {
        int disk = pop(&source);
        push(&dest, disk);
        moveDisk('A', 'C', disk);
        return;
    }
    towerOfHanoi(numDisks - 1, source, dest, aux);
    int disk = pop(&source);
    push(&dest, disk);
    moveDisk('A', 'C', disk);
    towerOfHanoi(numDisks - 1, aux, source, dest);
}

int main()
{
    int numDisks = 3; // Number of disks
    struct StackNode *source = NULL;
    struct StackNode *aux = NULL;
    struct StackNode *dest = NULL;

    for (int i = numDisks; i >= 1; i--)
    {
        push(&source, i);
    }

    printf("Steps to solve Tower of Hanoi with %d disks:\n", numDisks);
    towerOfHanoi(numDisks, source, aux, dest);

    return 0;
}
