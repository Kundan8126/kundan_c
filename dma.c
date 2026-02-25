#include <stdio.h>
#include <stdlib.h> 

int main() {
    int n, i;
    int *ptr;

 
    printf("How many numbers do you want to enter");
    scanf("%d", &n);

    ptr = (int*)malloc(n * sizeof(int));

    if (ptr == NULL) {
        printf("Memory not allocated.\n");
        return 1; 
    }


    printf("Enter %d numbers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &ptr[i]);
    }

    // 4. Print the numbers back
    printf("The numbers you entered are: ");
    for (i = 0; i < n; i++) {
        printf("%d ", ptr[i]);
    }

    // 5. Deallocate memory
    free(ptr);

    return 0;
}