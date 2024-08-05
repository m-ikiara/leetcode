#include <stdio.h>
#include <stdlib.h>

int mySqrt(int x);

int
mySqrt(int x)
{
    if (x < 0) return 0;

    double guess = 2.0;

    for (int i = 69; i > 0; --i) guess = 0.5 * (guess + (double) x / guess);

    return (int) guess;
}

int
main(void)
{
    printf("--------------------------------------------------------------\n");
    for (int i = 0; i <= 100; i++) {
        printf("[INFO] The square root of %d is %d\n", i, mySqrt(i));
    }
    printf("--------------------------------------------------------------\n");

    return 0;
}
