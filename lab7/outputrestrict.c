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

void insertFront(int value) {
    if (isFull()) return printf("Overflow\n");
    if (isEmpty()) front = rear = 0;
    else front = (front - 1 + MAX) % MAX;
    deque[front] = value;
}

void deleteFront() {
    if (isEmpty()) return printf("Underflow\n");
    printf("Deleted %d from front\n", deque[front]);
    if (front == rear) front = rear = -1;
    else front = (front + 1) % MAX;
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
    // Predefined operations:
    insertRear(10);
    insertRear(20);
    insertFront(5);
    insertRear(30);
    insertFront(1);
    display();

    deleteFront();
    display();

    insertRear(40);  // Should cause overflow if full
    display();

    deleteFront();
    deleteFront();
    display();

    return 0;
}
