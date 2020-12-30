/*
File: reverse.c
Date: 12/19/2020
Author: Garret DeCarlo
Purpose: Create a function that takes a pointer to a string, reverses the string, 
    and returns it in the same memory. Then, configure main() to take in arguments 
    from the command line and return the expected output to the console.
*/

#include <stdio.h>
#include <string.h>

void reverseString(char *stringP) {
    int length = strlen(stringP);
    char *startP = stringP;  // starting address of string
    char *backP = (startP + length - 1);  // backward iterator
    for (int i = 0; i < length/2; i++) {
        char tmp = *stringP;  // store value at current pointer
        *stringP = *(backP - i);  // replace the current pointer value with backend value
        *(backP - i) = tmp;  // replace backend value with stored value
        stringP++;  // increment pointer to next char position
    }
}

void displayAddresses(char *stringP) {
    int length = strlen(stringP);
    printf("Addresses:\n");
    for (int i = 0; i < length; i++) {
        printf("%p\n", stringP);
        stringP++;
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Error: missing command line arguments\n");
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        //displayAddresses(argv[i]);
        reverseString(argv[i]);
    }

    for (int i = argc - 1; i > 0; i--) {
        //displayAddresses(argv[i]);
        printf("%s ", argv[i]);
    }
    printf("\n");

    return 0;
}