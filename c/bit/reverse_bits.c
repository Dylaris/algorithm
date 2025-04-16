/*
 * NAME
 ** Reverse Bits
 *
 * PURPOSE
 ** Reverse the bits of a given 32-bit unsigned integer.
 * 
 * PSEUDO-CODE
 ** res = 0
 ** FOR i from 0 to 31
 **   res <<= 1
 **   res |= n & 1
 **   n >>= 1
 ** RETURN res
 *
 * COST
 ** time:  O(log n)
 ** space: O(1)
 */

#include <stdio.h>

static unsigned int reverse_bits(unsigned int n)
{
    unsigned int res = 0;
    for (size_t i = 0; i < 32; i++) {
        res = (res << 1) | (n & 1);
        n >>= 1;
    }
    return res;
}

int main(void)
{
    printf("reverse 00000010100101000001111010011100 (43261596): %u\n", reverse_bits(43261596));
    printf("reverse 11111111111111111111111111111101 (4294967293): %u\n", reverse_bits(4294967293));
    return 0;
}