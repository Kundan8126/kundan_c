#include<stdio.h>
int main (){
printf("helo");
return 0;
}
#include <stdio.h>

void collatz_sequence(int n) {
    printf("Collatz sequence for %d: ", n);
    while (n != 1) {
        printf("%d -> ", n);
        if (n % 2 == 0) {
            n = n / 2;  // If even, divide by 2
        } else {
            n = 3 * n + 1;  // If odd, multiply by 3 and add 1
        }
    }
    printf("1\n");
}

int main() {
    int num;
    printf("Enter a positive integer: ");
    scanf("%d", &num);

    if (num <= 0) {
        printf("Please enter a positive integer.\n");
    } else {
        collatz_sequence(num);
    }

    return 0;
}
