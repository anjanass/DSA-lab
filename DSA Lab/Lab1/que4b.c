#include <stdio.h>

void swapByReference(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int a = 5, b = 10;
    printf("Before swapByReference - a: %d, b: %d\n", a, b);
    swapByReference(&a, &b);
    printf("After swapByReference - a: %d, b: %d\n", a, b);
    return 0;
}
// this is a code to explain value of a and b changes after calling swapbyreference function beause it uses pass by reference.here function receives addresses of a and b so any change made to a and b indside the function affects the original variables in main.
