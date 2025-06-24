
#include <stdio.h>

void swapByValue(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
    printf("Inside swapByValue - a: %d, b: %d\n", a, b);
}

int main() {
    int a = 5, b = 10;
    printf("Before swapByValue - a: %d, b: %d\n", a, b);
    swapByValue(a, b);
    printf("After swapByValue - a: %d, b: %d\n", a, b);
    return 0;
}
//this is a code to explain value of a and b remains unchanged after calling swapByValue function because it uses pass by value.
//the function receives copies of the values of a nd b so any change made to a and b inside the function does not affect the original variables in main.