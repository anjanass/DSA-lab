#include <stdio.h>

int factorialIterative(int n) {
    int fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

int factorialRecursive(int n) {
    if (n == 0 || n == 1)
        return 1;
    else
        return n * factorialRecursive(n - 1);
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    printf("Factorial (iterative) of %d is %d\n", num, factorialIterative(num));
    printf("Factorial (recursive) of %d is %d\n", num, factorialRecursive(num));
    return 0;
}
//this is a code to calculate factorial of a number using both iterative and recursive methods.
//the iterative methods uses a loop to calculate the factorial,while the recursive methid calls itself with a decremented value until it reaches the base case of 0 or 1.