
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a student
struct Student {
    char name[50];
    int physics;
    int chemistry;
    int biology;
    int total;
};

// Function to merge two subarrays
void merge(struct Student arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Create temporary arrays
    struct Student L[n1], R[n2];

    // Copy data to temporary arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Merge the temporary arrays back into arr[l..r]
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i].total >= R[j].total) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Merge sort function
void mergeSort(struct Student arr[], int l, int r) {
    if (l < r) {
        // Find the middle point
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        // Merge the sorted halves
        merge(arr, l, m, r);
    }
}

int main() {
    struct Student students[10];
    
    // Input student details
    strcpy(students[0].name, "John");
    students[0].physics = 80;
    students[0].chemistry = 75;
    students[0].biology = 85;
    students[0].total = students[0].physics + students[0].chemistry + students[0].biology;
    
     strcpy(students[1].name, "Emma");
    students[1].physics = 90;
    students[1].chemistry = 85;
    students[1].biology = 80;
    students[1].total = students[1].physics + students[1].chemistry + students[1].biology;

    strcpy(students[2].name, "Michael");
    students[2].physics = 70;
    students[2].chemistry = 80;
    students[2].biology = 95;
    students[2].total = students[2].physics + students[2].chemistry + students[2].biology;
    
    strcpy(students[3].name, "Alice");
students[3].physics = 85;
students[3].chemistry = 90;
students[3].biology = 88;
students[3].total = students[3].physics + students[3].chemistry + students[3].biology;

strcpy(students[4].name, "Bob");
students[4].physics = 78;
students[4].chemistry = 82;
students[4].biology = 85;
students[4].total = students[4].physics + students[4].chemistry + students[4].biology;

strcpy(students[5].name, "Sophia");
students[5].physics = 92;
students[5].chemistry = 88;
students[5].biology = 80;
students[5].total = students[5].physics + students[5].chemistry + students[5].biology;

strcpy(students[6].name, "James");
students[6].physics = 75;
students[6].chemistry = 80;
students[6].biology = 82;
students[6].total = students[6].physics + students[6].chemistry + students[6].biology;

strcpy(students[7].name, "Olivia");
students[7].physics = 88;
students[7].chemistry = 85;
students[7].biology = 90;
students[7].total = students[7].physics + students[7].chemistry + students[7].biology;

strcpy(students[8].name, "William");
students[8].physics = 85;
students[8].chemistry = 86;
students[8].biology = 75;
students[8].total = students[8].physics + students[8].chemistry + students[8].biology;

strcpy(students[9].name, "Amelia");
students[9].physics = 79;
students[9].chemistry = 75;
students[9].biology = 85;
students[9].total = students[9].physics + students[9].chemistry + students[9].biology;



    // Similarly input details for other students...

    // Perform merge sort based on total marks
    mergeSort(students, 0, 9);

    // Output ranks
    printf("Rank\tName\tPhysics\tChem\tBiology\tTotal\n");
    for (int i = 0; i < 10; i++) {
        printf("%d\t%s\t%d\t%d\t%d\t%d\n", i+1, students[i].name, students[i].physics, students[i].chemistry, students[i].biology, students[i].total);
    }

    return 0;
}

