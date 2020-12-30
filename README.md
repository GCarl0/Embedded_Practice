# Embedded_Practice

Author: Garret DeCarlo

Date: 12/30/2020

This directory contains practice problems that were completed in preparation for c-programming:

### reverse.c

Create a function that takes a pointer to a string, reverses the string, and returns it in the same memory. Then, configure main() to take in arguments from the command line and return the expected output to the console.

### format.c

Create a function that takes a pointer to a string, and copies that input string into another string, making the following changes along the way (You should be able to do this with exactly one pass through the copying loop):
* convert all capital letters to lower case
* strip all leading whitespace (so the first character in the output string is guaranteed to be non-whitespace, unless the output is empty)
* convert all remaining forms of whitespace to the space character
* collapse runs of multiple spaces together into a single space
* strip any trailing whitespace (so the last character in the output string is guaranteed to be non-whitespace, unless the output is empty)

### rgb.c

Given RGB percentages, return a hex string.
