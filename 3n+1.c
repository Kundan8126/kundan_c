#include<stdio.h>
void sequence(int n){
    while(n!=1){
        if(n%2==0){
            n=n/2;
        }
        else{
            n=3*n+1;
        }
        printf("    %d",n);
    
    }

    printf("\n");
}
int main() {
    int num;
    printf("Enter a positive integer: ");
    scanf("%d", &num);

    if (num <= 0) {
        printf("Please enter a positive integer.\n");
    } else {
        sequence(num);
    }
    return 0;
}
// 142-16
// 11 7 4 2 1 6


// C implementation of Shell Sort
#include <stdio.h>

/* function to sort arr using shellSort */
int shellSort(int arr[], int n)
{
    // Start with a big gap, then reduce the gap
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        // Do a gapped insertion sort for this gap size.
        for (int i = gap; i < n; i++)
        {
            int temp = arr[i];
            int j;

            // shift earlier gap-sorted elements up until the correct location is found
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];

            // put temp (the original arr[i]) in its correct location
            arr[j] = temp;
        }
    }
    return 0;
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int arr[] = {12, 34, 54, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array before sorting:\n");
    printArray(arr, n);

    shellSort(arr, n);

    printf("Array after sorting:\n");
    printArray(arr, n);

    return 0;
}