/*
 * NAME
 ** Sum Bits
 *
 * PURPOSE
 ** Get the sum of tow integer using bit operation
 * 
 * PSEUDO-CODE
 ** WHILE b != 0
 **   tmp_sum = a ^ b
 **   carry = (a & b) << 1
 **   a = tmp_sum
 **   b = carry
 ** RETURN a
 *
 * COST
 ** time:  O(log n)
 ** space: O(1)
 */

#include <stdio.h>

static int sum(unsigned int a, unsigned int b)
{
    while (b) {
        unsigned int tmp = a ^ b;
        unsigned int carry = (a & b) << 1;
        a = tmp;
        b = carry;
    }
    return a;
}

int main(void)
{
    printf("1+2 = %d\n", sum(1, 2));
    printf("2+3 = %d\n", sum(2, 3));
    printf("0-3 = %d\n", sum(0, -3));
    printf("2-3 = %d\n", sum(2, -3));
    printf("2+0 = %d\n", sum(2, 0));
    printf("-2-3 = %d\n", sum(-2, -3));
    return 0;
}