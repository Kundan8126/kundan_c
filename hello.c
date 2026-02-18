// #include<stdio.h>
// #include<conio.h>
// int main(){
//     int age;
//     printf("enter your age");
//     scanf("%d",&age);
//     if(age>=18) {
//         printf("you are eligible to vote");
//     }
//     getch();
// }



//=====================================================================//
// #include <stdio.h>

// int main() {
//     int day;

//     printf("Enter a number (1-12) for the month of year: ");
//     scanf("%d", &day);

//     switch (day) {
//         case 1:
//             printf("It is jan.\n");
//             break; // Exits the switch block so it doesn't run the next cases
//         case 2:
//             printf("It is feb.\n");
//             break;
//         case 3:
//             printf("It is mar.\n");
//             break;
//         case 4:
//             printf("It is apr.\n");
//             break;
//         case 5:
//             printf("It is may.\n");
//             break;
//         case 6:
//             printf("It is jun.\n");
//             break;
//         case 7:
//             printf("It is jul.\n");
//             break;
//         case 8:
//             printf("It is aug.\n");
//             break;
//         case 9:
//             printf("It is sep.\n");
//             break;
//         case 10:
//             printf("It is oct.\n");
//             break;
//         case 11:
//             printf("It is nov.\n");
//             break;
//         case 12:
//             printf("It is dec.\n");
//             break;
//         default:
//             // Runs if the user entered a number other than 1, 2, or 3
//             printf("Invalid input!\n");
//     }

//     return 0;
// }

//=====================================================================//


// #include <stdio.h>

// int main() {
//     int count = 3;

//     printf("Initiating countdown...\n");

//     while (count > 0) {
//         printf("%d...\n", count);
//         count--; 
//     }

//     printf("Liftoff!\n");
//     return 0;
// }

//=====================================================================//


// #include <stdio.h>

// int main() {
//     int pin;

//     // This block will run at least once before checking the condition
//     do {
//         printf("Please enter your 4-digit PIN (Hint: it's 1234): ");
//         scanf("%d", &pin);
//     } while (pin != 1234);{ // If the PIN is wrong, it loops back up

//     printf("PIN accepted. Access granted!\n");}
//     return 0;
// }


//=====================================================================//
// #include <stdio.h>

// int main() {
//     int rows, columns;
    

//     // This loop for traverse
//     // pyramid from top to bottom
//     printf("Enter the number of rows for the pyramid: ");
//     scanf("%d",&rows);
//     for (int i = 0; i < rows; i++) {

//         // Inner loop for printing 
//         // character in each rows
        
//         for (int j = 0; j <= i; j++) {
//             printf("* ");
//         }
//         printf("\n");
//     }
//     return 0;
// }

//=====================================================================//
// #include <stdio.h>
// #include <string.h>

// int main() {
//     char a[20] = "Hello";
//     char b[20] = "World";

//     strcat(a, b);
//     printf("%s\n", a);

//     printf("Length = %lu", strlen(a));
//     return 0;
// }


//=====================================================================//
// #include <stdio.h>
// #include <ctype.h>

// int main() {
//     char ch = 'a';

//     if (isdigit(ch))
//         printf("Alphabet\n");

//     printf("%c\n", toupper(ch));
//     return 0;
// }

//=====================================================================//


// #include <stdio.h>
// #include <time.h>

// int main() {
//     time_t t;
//     time(&t);
//     printf("Current time: %s", ctime(&t));
//     return 0;
// }

//=====================================================================//

// #include <stdio.h>
// #include <stdbool.h>

// int main() {
//     int a;
//     printf("Enter a number: ");
//     scanf("%d", &a);
//     bool isReady = true;

//     if (isReady == 10){

//     }
//         printf("Ready!\n");

//     return 0;
// }

//=====================================================================//

// #include <stdio.h>
// #include <limits.h>
// #include <float.h>

// int main() {
//     printf("INT MAX = %d\n", INT_MAX);
//     printf("INT MAX = %d\n", FLT_MAX);
//     printf("INT MIN = %d\n", CHAR_MIN);
//     return 0;
// }


//=====================================================================//

