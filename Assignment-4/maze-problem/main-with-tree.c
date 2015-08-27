/**
 * Maze Problem
 * You are provided a matrix of size N*N with source position at (0,0) and
 * destination at (N-1,N-1) in a 2D array. Some of the positions in the array are marked as 0 which are blocked cells, 
 * rest being marked 1.
 * A path is a connected sequence of elements from (0,0) to (N-1,N-1) which consists of 1. A sequence of 1s in the 2D 
 * array is connected if every 1 in the sequence is adjacent (the above or left neighbour) to the next 1 in the sequence.
 * 
 * For example, in the following matrix,
 * 1 1 0
 * 0 1 1
 * 1 0 1 
 * 
 * the 1s marked in blue is a connected path from (0,0) to (2,2)
 * Note that cells at (0,0) and (N-1,N-1) are always 1. You can either make
 * movement towards right or down, i.e., from position (x,y), you can go to either the position (x,y+1) or (x+1,y).
 * Input
 * First line consists of the size of the input array N (<=50), following that would
 * be the state of NxN maze which would consist of 0s and 1s.
 * Output
 * You have to print "POSSIBLE" if there exists a path between the source and the destination otherwise print "NOT 
 * POSSIBLE". 
 * 
 * ------------------------------------------------------------------
 * TEST CASES
 * ------------------------------------------------------------------
 *                      INPUT                           OUTPUT
 * Test Case 1          4                               POSSIBLE
 *                      1 1 1 1
 *                      1 1 1 1
 *                      1 1 1 1
 *                      1 1 1 1                    
 * 
 * Test Case 2          3                               NOT POSSIBLE
 *                      1 0 0
 *                      0 0 0
 *                      0 0 1                      
 * -------------------------------------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>

struct Cell {
    int x;
    int y;
    struct Cell *bottom;
    struct Cell *right;
    struct Cell *parent;
} *node, *temp;
int **mx;
int n, possible = 0;

void traverse(int x, int y, struct Cell *t) {
    if (x == (n-1) || y == n-1) {
        return;
    }
    
    if (mx[++x][y] == 1) {
        if (x == n - 1 && y == n - 1) {
            possible = 1;
            return;
        }
        temp = t;
        t->right = (struct Cell *) malloc(sizeof(struct Cell));
        t = t->right;
        
        t->right = NULL;
        t->bottom = NULL;
        t->parent = temp;
        t->x = x;
        t->y = y;
        
        traverse(x, y, t);
    }
    
    if (mx[x][++y] == 1) {
        if (x == n - 1 && y == n - 1) {
            possible = 1;
            return;
        }
        
        temp = t;
        t->bottom = (struct Cell *) malloc(sizeof(struct Cell));
        t = t->bottom;
        
        t->right = NULL;
        t->bottom = NULL;
        t->parent = temp;
        t->x = x;
        t->y = y;
        
        traverse(x, y, t);
    }
}

int main() {
    int i, j;
    
    node = (struct Cell *) malloc(sizeof (struct Cell));

    node->parent = NULL;
    node->bottom = NULL;
    node->right = NULL;
    node->x = 0;
    node->y = 0;

    printf("Enter Size of matrix (an integer): ");
    scanf("%d", &n);
    mx = (int**) malloc(n * sizeof (int));

    for (i = 0; i < n; i++) {
        mx[i] = (int *) malloc(n * sizeof (int));

        for (j = 0; j < n; j++) {
            scanf("%d", &mx[i][j]);
        }
    }

    printf("\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", mx[i][j]);
        }
        printf("\n");
    }
    
    traverse(0, 0, node);
    
    printf("\n");
    if (possible == 1) {
        printf("POSSIBLE");
    } else {
        printf("NOT POSSIBLE");
    }


    return EXIT_SUCCESS;
}