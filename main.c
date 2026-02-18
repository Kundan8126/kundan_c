#include<stdio.h>
#include "mymath.h"
int main(){
    double num;
    printf("Enter a number: ");
    scanf("%lf", &num);
    
    printf("Cube of %.2lf is %.2lf\n", num, cube(num));
    printf("Cube root of %.2lf is %.2lf\n", num, cuberoot(num));
    
    return 0;
}