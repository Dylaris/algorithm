/*
 * NAME
 ** Quck Pow
 *
 * PURPOSE
 ** Computes the power of a number x raised to an integer n (x^n) using the 
 ** efficient method of exponentiation by squaring. This method reduces the 
 ** time complexity to O(log n).
 * 
 * PSEUDO-CODE
 ** IF n is negative:
 **   x = 1 / x
 **   n = -n
 ** ans = 1
 ** WHILE n is not zero:
 **   IF n is odd:
 **     ans = ans * x
 **   x = x * x
 **   n = n >> 1
 ** RETURN ans
 *
 * COST
 ** time:  O(log n)
 ** space: O(1)
 */

#include <stdio.h>

static double quick_pow(double x, int n)
{
    x = (n > 0) ? x : 1 / x;
    n = (n > 0) ? n : -n;

    double ans = 1;

    while (n) {
        if (n & 1) ans *= x;
        x = x * x;
        n >>= 1;
    }
    return ans;
}

int main(void)
{
    printf("2.1 ^ 9: %f\n", quick_pow(2.1, 9));
    printf("2.1 ^ -9: %f\n", quick_pow(2.1, -9));
    return 0;
}
