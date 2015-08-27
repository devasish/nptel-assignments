#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int c[] = {1, 3, 5};
int ct = 0;

int step(int depth, int dynAmount, int amount) {
    int rem, i, x, maxDiv;
    printf("depth=%d,dynAmount=%d\n", depth,dynAmount);
    
    for (maxDiv = floor(dynAmount / c[depth]) ; maxDiv >= 0; maxDiv--) {
        rem = dynAmount - (c[depth] * maxDiv) ;
        if (rem == 0 ){
            printf("A\n");
            ct++;
        } else if(--depth >= 0){
            printf("B\n");
            step(depth, rem, amount);
        } else {
            printf("C\n");
        }
    }
    
    return 0;
}

int main() {
    int a;
    scanf("%d", &a);
    step(2, a, a);
    printf("%d", ct);
    step(1, a, a);
    printf("%d", ct);
//    step(0, a, a);
//    printf("%d", ct);
    return EXIT_SUCCESS;
}




//int main() {
//    int t, a, i, count = 0, x;
//    t = 1;
//    int maxDiv,maxDiv2, maxDiv3, rem, rem2, rem3, j, k; 
//    for (x = 0; x < t; x++) {
//        scanf("%d", &a);
//        //count = step(2, floor(a / c[2]), a, a, 0);
//        //printf("[%d]", ct);
//        
//        for (i = 2; i >= 0; i--) {
//            maxDiv = floor(a / c[i]);
//            for (maxDiv; maxDiv > 0; maxDiv--) {
//                if ((rem = a % (c[i] * maxDiv)) == 0) {
//                    printf("[%d X %d]", c[i], maxDiv);
//                    count++;
//                } else if (i > 0){
//                    for (j = i - 1; j >= 0; j--) {
//                        maxDiv2 = floor(rem / c[j]);
//                        if ((rem2 = rem % (c[j] * maxDiv2)) == 0) {
//                            printf("[%d X %d]", c[j], maxDiv2);
//                            count++;
//                        } else if(j > 0){
//                            for (k = j - 1; k >= 0; k--) {
//                                maxDiv3 = floor(rem2 / c[k]);
//                                if ((rem3 = rem2 % (c[k] * maxDiv3)) == 0) {
//                                    printf("[%d X %d]", c[k], maxDiv3);
//                                    count++;
//                                }
//                            }
//                        }
//                    }
//                }
//            }
//        }
//    }
//    printf("%d", count);
//    return EXIT_SUCCESS;
//}



