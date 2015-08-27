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

//int **mx;
int possible = 0;

void traverse(int x, int y, int **mx, int n) {
    int x_ = x + 1;
    int y_ = y + 1;
    int max_i = n - 1;
    
    if (x_ < n && y < n && mx[x_][y] == 1) {
        if (x_ == max_i && y == max_i) {
            possible = 1;
            return;
        } else {
            traverse(x_, y, mx, n);
        }
    }

    if (x < n && y_ < n && mx[x][y_] == 1) {
        if (x == max_i && y_ == max_i) {
            possible = 1;
            return;
        } else {
            traverse(x, y_, mx, n);
        }
    }
}

void output() {
    if (possible == 1) {
        printf("POSSIBLE");
    } else {
        printf("NOT POSSIBLE");
    }
}

int main() {
    int **mx;
    int i, j, n;
    scanf("%d", &n);
    
    if (n > 50) {
        output();
        return EXIT_SUCCESS;
    }
    
    mx = (int**) malloc(n * sizeof (int));

    for (i = 0; i < n; i++) {
        mx[i] = (int *) malloc(n * sizeof (int));

        for (j = 0; j < n; j++) {
            scanf("%d", &mx[i][j]);
        }
    }
    
    if (n == 1) {
        possible = mx[0][0] == 1 ? 1 : 0;
    } else if (mx[0][0] == 1 && mx[n-1][n-1] == 1) {
        traverse(0, 0, mx, n);
    }

    output();

    return EXIT_SUCCESS;
}