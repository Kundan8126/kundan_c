#include <string.h>
#include <stdio.h>

/* Structure definition */
struct Student {
    int id;
    char name[20];
    float marks;
};

/* Function declaration */
int calculateSum(int arr[], int size);
void displayStudent(struct Student s);
void updateMarks(struct Student *s);

int main() {
    int numbers[5] = {10, 20, 30, 40, 50};
    int sum;

    struct Student s1 = {1, "Kundan", 75.5};

    sum = calculateSum(numbers, 5);
    printf("Sum of array = %d\n", sum);

    displayStudent(s1);

    updateMarks(&s1);
    displayStudent(s1);

    return 0;
}

/* Function definition */
int calculateSum(int arr[], int size) {
    int total = 0;

    for (int i = 0; i < size; i++) {
        total = total + arr[i];
    }

    return total;
}

void displayStudent(struct Student s) {
    printf("ID: %d\n", s.id);
    printf("Name: %s\n", s.name);
    printf("Marks: %.10f\n", s.marks);
}

void updateMarks(struct Student *s) {
    s->marks = s->marks + 5;
}
