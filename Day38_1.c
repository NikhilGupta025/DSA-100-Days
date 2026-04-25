#include <stdio.h>

#define MAX 5

int deque[MAX];
int front = -1;
int rear = -1;

void insertFront(int value)
{
    if(front == 0)
    {
        printf("Overflow\n");
        return;
    }

    if(front == -1)
        front = rear = 0;
    else
        front--;

    deque[front] = value;
}

void insertRear(int value)
{
    if(rear == MAX-1)
    {
        printf("Overflow\n");
        return;
    }

    if(front == -1)
        front = rear = 0;
    else
        rear++;

    deque[rear] = value;
}

void deleteFront()
{
    if(front == -1)
    {
        printf("Underflow\n");
        return;
    }

    printf("Deleted: %d\n", deque[front]);

    if(front == rear)
        front = rear = -1;
    else
        front++;
}

void deleteRear()
{
    if(front == -1)
    {
        printf("Underflow\n");
        return;
    }

    printf("Deleted: %d\n", deque[rear]);

    if(front == rear)
        front = rear = -1;
    else
        rear--;
}

void display()
{
    int i;

    if(front == -1)
    {
        printf("Empty\n");
        return;
    }

    for(i = front; i <= rear; i++)
        printf("%d ", deque[i]);

    printf("\n");
}

int main()
{
    insertRear(10);
    insertRear(20);
    insertFront(5);

    display();

    deleteFront();
    deleteRear();

    display();

    return 0;
}