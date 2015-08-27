/**
Difficulty : Medium

You are given a string of characters, or numbers. Find the minimum number of characters to be inserted into the string in order to obtain a palindrome. 
A palindrome is a word, phrase, number, or other sequence of symbols or elements that reads the same forward or reversed. 

For example, the string abcbd can be transformed into a palindrome ("dabcbad" or "adbcbda"). However, inserting fewer than 2 characters will not produce a palindrome.

Input Format:
First line contains an integer 'n' specifying the length of the string, where 3<=n<=20
Second line contains a string of length n. 

Note: Upper-case and lower-case characters are considered as different. Elements of the string are either English alphabets or numerals.

Output Format:
One line containing the minimum number of insertions required to make the string a palindrome 
 * TEST CASES
 *                      INPUT                           OUTPUT
 * Test Case 1          5                               0
 *                      nitin
 * 
 * Test Case 2          7                               1
 *                      aabbaab
 */


#include <stdio.h>
#include <stdlib.h>

int inArray(char ch, char str[], int size) {
    int i, j = -1;
    for (i = 0; i < size; i++) {
        if (ch == str[i]) {
            j = i;
            break;
        }
    }
    
    return j;
}

int main() {
    int n, i;
    char *str, *uniq;
    int *countArr;
    int uniqIndex = 0, index, oddCount = 0;
    
    scanf("%d", &n);
    
    str         = (char*)       malloc(n * sizeof(char));
    uniq        = (char*)       malloc(n * sizeof(char));
    countArr    = (int*)        malloc(n * sizeof(int));
    
    getchar();
    
    for(i = 0; i < n; i++) {
        str[i] = getchar();
        if (i == 0) {
            uniq[uniqIndex]   = str[i];
            countArr[uniqIndex] = 1;
            uniqIndex++;
        }
        else if((index = inArray(str[i], &uniq[0], uniqIndex + 1)) == -1){
            uniq[uniqIndex]     = str[i];
            countArr[uniqIndex] = 1;
            uniqIndex++;
        }
        else {
            countArr[index]++;
        }
    }
    
    for (i = 0; i < uniqIndex; i++) {
        if (countArr[i] % 2 != 0) {
            oddCount++;
        }
        
        printf("\n%c = %d", uniq[i], countArr[i]);
    }
    
    printf("\n%d", oddCount - 1);
    
    return EXIT_SUCCESS;
}