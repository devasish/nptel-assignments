/**
 * Write a recursive program that inputs a line of characters from the user. 
 * The line may contain blanks. It outputs the line with the characters reversed. 
 * The input ends with EOF (end of file).
 * NOTE: You have to use recursion to solve this, and are NOT allowed to use array to store the input!!
 * 
 * Example:
 * INPUT
 * This is easy
 * 
 * OUTPUT
 * ysae si sihT
 * ------------------------------------------------------------------
 * TEST CASES
 *                      INPUT                           OUTPUT
 * Test Case 1          This is easy                    ysae si sihT
 * Test Case 2          TEST CASES                      SESAC TSET
 * Test Case 3          !@#$@ &%^                       ^%& @$#@!
 * -------------------------------------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i = 0, j, k;
    char str[255], ch, temp;
    
    while((ch = getchar()) != EOF) {
        str[i++] = ch;
    }
    str[i] = '\0';
    
    for (j = 0, k = i - 1; j < k ; j++, k--) {
        temp = str[j];
        str[j] = str[k];
        str[k] = temp;
    }
    
    
    puts(str);
    
    return EXIT_SUCCESS;
}