// #include <stdio.h>
// #include <stdlib.h>

// struct Student {
//     char name[50];
//     int roll;
// };

// int main() {
//     int n, i;
//     struct Student *ptr; 

//     printf("Enter the number of students: ");
//     scanf("%d", &n);

//     ptr = (struct Student*)malloc(n * sizeof(struct Student));

//     if (ptr == NULL) {
//         printf("Memory allocation failed!\n");
//         return 1;
//     }

//     // Inputting data
//     for (i = 0; i < n; i++) {
//         printf("\nEnter details for Student %d:\n", i + 1);


//         printf("Name: ");
//         scanf("%s", ptr[i].name); 

//         printf("Roll No: ");
//         scanf("%d", &ptr[i].roll);
//     }


//     printf("\n--- Student Records ---\n");
//     for (i = 0; i < n; i++) {

//         printf("Student %d: Roll No: %d, Name: %s\n", i + 1, ptr[i].roll, ptr[i].name);
//     }

//     // Freeing the memory
//     free(ptr);

//     return 0;
// }


#include <stdio.h>

#include <stdlib.h>

struct Student {
    char name[50];
    int roll;
};

int main() {
    int n, i, j;
    struct Student *ptr;

    printf("Enter the number of students: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid number of students!\n");
        return 1;
    }

    ptr = (struct Student*)malloc(n * sizeof(struct Student));
    if (ptr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }


    for (i = 0; i < n; i++) {
        printf("\nEnter details for Student %d:\n", i + 1);

        printf("Name: ");
        scanf("%s", ptr[i].name);

  
        while (1) {
            int duplicate = 0;

            printf("Roll No (positive & unique): ");
            scanf("%d", &ptr[i].roll);

       
            if (ptr[i].roll <= 0) {
                printf(" Roll number must be positive. Try again.\n");
                continue;
            }

   
            for (j = 0; j < i; j++) {
                if (ptr[i].roll == ptr[j].roll) {
                    duplicate = 1;
                    break;
                }
            }

            if (duplicate) {
                printf("Roll number already exists. Enter a unique roll number.\n");
            } else {
                break;  
            }
        }
    }

    printf("\n--- Student Records ---\n");
    for (i = 0; i < n; i++) {
        printf("Student %d: Roll No: %d, Name: %s\n",
               i + 1, ptr[i].roll, ptr[i].name);
    }

    free(ptr);
    return 0;
}