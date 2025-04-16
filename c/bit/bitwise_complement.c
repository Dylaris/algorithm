/*
 * NAME
 ** Bitwise Complement
 *
 * PURPOSE
 ** Given a decimal number N, return the decimal integer 
 ** corresponding to the complement of its binary representation
 * 
 * PSEUDO-CODE
 ** IF n == 0 THEN
 **   RETURN 1
 ** SET res to 0
 ** SET count to 0
 ** WHILE n != 0
 **   IF n & 1 == 0 THEN
 **     res |= 1 << count
 **   count += 1
 **   n >>= 1
 ** RETURN res
 *
 * COST
 ** time:  O(log n)
 ** space: O(1)
 */

#include <stdio.h>

static unsigned int bitwise_complement(unsigned int n)
{
    if (n == 0) return 1;
    unsigned int res = 0, count = 0;
    while (n) {
        if ((n & 1) == 0) res |= (1 << count);
        count += 1;
        n >>= 1;
    }
    return res;
}

int main(void)
{
    printf("5: %u\n", bitwise_complement(5));
    printf("7: %u\n", bitwise_complement(7));
    printf("10: %u\n", bitwise_complement(10));
    return 0;
}