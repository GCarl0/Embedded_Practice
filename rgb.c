/*
File: rgb.c
Date: 12/22/2020
Author: Garret DeCarlo
Purpose: Given RGB percentages, return a hex string.
*/

#include <math.h>
#include <stdio.h>
#include <string.h>

static const int RGB_SIZE = 7;  // Total byte size for rgb hex string
static const int HEX_SIZE = 2;  // Total byte size for one color hex value

char *decToHex(int *num) {
    static char hexVal[HEX_SIZE];
    char hexString[16] = "0123456789ABCDEF";

    hexVal[0] = hexString[*num / 16];
    hexVal[1] = hexString[*num % 16];

    return hexVal;
}

// Convert RGB percentage to decimal value (ASCII)
int percToDec(float *num) {
    return ceil(*num * 255.0);  // Round up value
}

float getPercVal(float *num) {
    return *num / 100.0;
}

void *getHexCode(float *percRed, float *percGrn, float *percBlu) {
    static char hexCode[RGB_SIZE];

    int decRed, decGrn, decBlu;

    decRed = percToDec(percRed);
    decGrn = percToDec(percGrn);
    decBlu = percToDec(percBlu);

    printf("R: %d, G: %d, B: %d\n", decRed, decGrn, decBlu);

    memcpy(hexCode, "#", 1);  // Add hashtag to mark beginning of rgb hex string
    memcpy(&hexCode[strlen(hexCode)], decToHex(&decRed), HEX_SIZE);  // concat red hex value
    memcpy(&hexCode[strlen(hexCode)], decToHex(&decGrn), HEX_SIZE);  // concat green hex value
    memcpy(&hexCode[strlen(hexCode)], decToHex(&decBlu), HEX_SIZE);  // concat blue hex value
    
    return hexCode;
}

int main() {
    char *hexString;
    
    float percRed, percGrn, percBlu;

    printf("Red (%%):");
    scanf("%f", &percRed);
    printf("Green (%%):");
    scanf("%f", &percGrn);
    printf("Blue (%%):");
    scanf("%f", &percBlu);

    percRed = getPercVal(&percRed);
    percGrn = getPercVal(&percGrn);
    percBlu = getPercVal(&percBlu);

    hexString = getHexCode(&percRed, &percGrn, &percBlu);
    printf("Hex Value: \"%s\"\n", hexString);

    return 0;
}