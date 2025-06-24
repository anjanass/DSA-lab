#include <stdio.h>
#define MAX 5

int deque[MAX], front = -1, rear = -1;

int isFull() { return (front == 0 && rear == MAX - 1) || (rear + 1) % MAX == front; }
int isEmpty() { return front == -1; }

void insertRear(int value) {
    if (isFull()) return printf("Overflow\n");
    if (isEmpty()) front = rear = 0;
    else rear = (rear + 1) % MAX;
    deque[rear] = value;
}

void deleteFront() {
    if (isEmpty()) return printf("Underflow\n");
    printf("Deleted %d from front\n", deque[front]);
    if (front == rear) front = rear = -1;
    else front = (front + 1) % MAX;
}

void deleteRear() {
    if (isEmpty()) return printf("Underflow\n");
    printf("Deleted %d from rear\n", deque[rear]);
    if (front == rear) front = rear = -1;
    else rear = (rear - 1 + MAX) % MAX;
}

void display() {
    if (isEmpty()) return printf("Deque is empty\n");
    printf("Deque: ");
    for (int i = front; ; i = (i + 1) % MAX) {
        printf("%d ", deque[i]);
        if (i == rear) break;
    }
    printf("\n");
}

int main() {
    int ch, val;
    while (1) {
        printf("\n1.Insert 2.DelFront 3.DelRear 4.Display 5.Exit: ");
        scanf("%d", &ch);
        if (ch == 5) break;
        if (ch == 1) {
            printf("Value: "); scanf("%d", &val);
            insertRear(val);
        } else if (ch == 2) deleteFront();
        else if (ch == 3) deleteRear();
        else if (ch == 4) display();
        else printf("Invalid\n");
    }
}
