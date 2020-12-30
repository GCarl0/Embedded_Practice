/*
File: format.c
Date: 12/20/2020
Author: Garret DeCarlo
Purpose: Create a function that takes a pointer to a string, and copies that 
    input string into another string, making the following changes along the way:
		* convert all capital letters to lower case
		* strip all leading whitespace (so the first character in the output 
          string is guaranteed to be non-whitespace, unless the output is empty)
		* convert all remaining forms of whitespace to the space character
		* collapse runs of multiple spaces together into a single space
		* strip any trailing whitespace (so the last character in the output 
          string is guaranteed to be non-whitespace, unless the output is empty)
	You should be able to do this with exactly one pass through the copying loop.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int MAX_STRING_LENGTH = 68;

void append(char *stringP, char add) {    
    *stringP = add;
    stringP++;  // incremement to the next pointer
    *stringP = '\0';
}

void snip(char *stringP) {
    stringP--;  // decremement to the previous pointer
    *stringP = '\0';
}

char *format(char *origPtr) {
    int curLength = 0;
    int spaceCount = 0;
    int strLength = strlen(origPtr);

    char stringStart = 0;
    char isWhiteSpace = 0;
    static char newString[MAX_STRING_LENGTH];
    
    if (strLength > MAX_STRING_LENGTH) {  // Error on oversized char array input
        fprintf(stderr, "ERROR: Input string length greater than maximum [%d] bytes\n", MAX_STRING_LENGTH);
        exit(-1);    
    } else if (strLength == 0) {  // Base case of null string
        return "";
    }

    for (int i = 0; i < strLength + 1; i++) {  // Iterate through the given string
        int decChar = (int)origPtr[i];  // Convert char to ASCII dec value

        if (8 < decChar && decChar < 14) {  // Convert all non-space whitespaces to spaces
            origPtr[i] = ' ';  
            decChar = 32;
        }

        isWhiteSpace = (decChar == 32);

        if (isWhiteSpace && !stringStart) {  // Ignore all leading spaces
            continue;
        } else {
            stringStart = 1;
            
            if (isWhiteSpace && spaceCount < 1) {  // Allow max of one space
                append(&newString[curLength], origPtr[i]);
                curLength++;
                spaceCount++;
            } else if (64 < decChar && decChar < 91) {  // Convert uppercase letters to lower
                append(&newString[curLength], (int)origPtr[i] + 32);
                curLength++;
                spaceCount = 0;
            } else if (!isWhiteSpace && decChar != 0) {  // If character is not null or space
                append(&newString[curLength], origPtr[i]);  // Place character into new string as-is
                curLength++;
                spaceCount = 0;
            } else if ((decChar == 0 ) && (int)origPtr[i-1] == 32) {  // If last character is space
                snip(&newString[curLength]);  // Snip trailing space
                curLength--;
            }
        }
    }

    return newString;
}

int main() {
    char origStr[MAX_STRING_LENGTH] = "\t   Garret    DeCarlo\t ";
    printf("Old String: \"%s\"\n", &origStr[0]);

    char *newStr = format(&origStr[0]);
    printf("New String: \"%s\"\n", newStr);

    return 0;
}
