/* 
 * File:   main.c
 * Author: MHBL-60
 *
 * Created on 21 July, 2016, 11:06 AM
 * URL : http://www.geeksforgeeks.org/lexicographic-permutations-of-string/
 * 
 * Print all permutations in sorted (lexicographic) order
======================================================
Given a string, print all permutations of it in sorted order. 
For example, if the input string is “ABC”, then output should be “ABC, ACB, BAC, BCA, CAB, CBA”.

We have discussed a program to print all permutations in this post, 
but here we must print the permutations in increasing order.

Following are the steps to print the permutations lexicographic-ally

1. Sort the given string in non-decreasing order and print it. 
The first permutation is always the string sorted in non-decreasing order.

2. Start generating next higher permutation. Do it until next higher permutation is not possible. 
If we reach a permutation where all characters are sorted in non-increasing order, 
then that permutation is the last permutation.
 * 
 * 
 * 
 *Steps to generate the next higher permutation:
=============================================
1. Take the previously printed permutation and find the rightmost character in it, 
which is smaller than its next character. Let us call this character as ‘first character’.

2. Now find the ceiling of the ‘first character’. Ceiling is the smallest character on right of ‘first character’, which is greater than ‘first character’. Let us call the ceil character as ‘second character’.

3. Swap the two characters found in above 2 steps.

4. Sort the substring (in non-decreasing order) after the original index of ‘first character’.

Let us consider the string “ABCDEF”. Let previously printed permutation be “DCFEBA”. 
The next permutation in sorted order should be “DEABCF”. Let us understand above steps to find next permutation. 
The ‘first character’ will be ‘C’. The ‘second character’ will be ‘E’. After swapping these two, we get “DEFCBA”. 
The final step is to sort the substring after the character original index of ‘first character’. 
Finally, we get “DEABCF”. 
 * 
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * 
 */
















int compare(const void *a, const void * b) {
    return ( *(char *) a - *(char *) b);
}

void swap(char *x, char *y) {
    char temp = *x;
    *x = *y;
    *y = temp;
}

int getCeil(char str[], int i, int size) {
    int j;
    int ceilIndex = i + 1;

    for (j = i + 1; j < size; j++) {
        if (str[j] > str[i] && str[j] < str[ceilIndex]) {
            ceilIndex = j;
        }
    }

    return ceilIndex;
}

void sortedPermutations(char *str) {
    int i;
    int isFinished = 0;
    int size = strlen(str);
    int ceilIndex;

    // Sort the chars in increasing order
    qsort(str, size, sizeof ( str[0]), compare);

    while (!isFinished) {
        printf("%s\n", str);

        // Find the right most char whose next char is greater than itself. Let us call it as 'first-char'
        for (i = size - 2; i >= 0; i--) {
            if (str[i] < str[i + 1]) {
                break;
            }
        }

        // if there is no such character, means all chars are in decreasing order. So we are done.
        if (i == -1) {
            isFinished = 1;
        }
        else {
            // Get the ceiling of first-char. Ceiling is the smallest char at the right greater than it.
            ceilIndex = getCeil(str, i, size);
            
            // Swap first-char and ceiling-char
            swap(&str[ceilIndex], &str[i]);

            // Sort the chars at the right of first-char in ascending order.
            qsort(str + i + 1, size - i - 1, sizeof (str[0]), compare);
        }
    }

}

int main(int argc, char** argv) {
    char str[32] = "";
    
    printf("Enter Text : ");
    scanf("%s", &str);
    
    sortedPermutations(str);

    return (EXIT_SUCCESS);
}

