/*
 * NAME
 ** Hamming Weight
 *
 * PURPOSE
 ** Get the number of set bit in a given positive integer
 * 
 * PSEUDO-CODE
 ** res = 0
 ** WHILE n != 0
 **   IF n & 1 == 1:
 **     res += 1
 **   n >>= 1
 ** RETURN res
 *
 * COST
 ** time:  O(log n)
 ** space: O(1)
 */

#include <stdio.h>

static unsigned int hamming_weight(unsigned int n)
{
    unsigned int res = 0;
    while (n) {
#if 0
        if ((n & 1) == 1) res += 1;
        n >>= 1;
#endif
        n &= n - 1;     /* Rest last set bit */
        res += 1;
    }
    return res;
}

int main(void)
{
    printf("11: %u\n", hamming_weight(11));
    printf("128: %u\n", hamming_weight(128));
    printf("2147483645: %u\n", hamming_weight(2147483645));
    return 0;
}