#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int generatedOTP;
    int userOTP;

    // Seed random number generator
    srand(time(0));

    // Generate 4-digit OTP (1000–9999)
    generatedOTP = rand() % 9000 + 1000;

    // Prototype: show OTP (in real systems this is sent via SMS/Email)
    printf("Generated OTP (for testing): %d\n", generatedOTP);

    // Ask user to enter OTP
    printf("Enter OTP: ");
    scanf("%d", &userOTP);

    // Verify OTP
    if (userOTP == generatedOTP) {
        printf("OTP verified successfully\n");
    } else {
        printf("Invalid OTP\n");
    }

    return 0;
}