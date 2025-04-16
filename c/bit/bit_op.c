/*
 * Function                                       +     Bitwise Operation              +          Example
 * -----------------------------------------------+----------------------------------- + ---------------------------
 * Set the rightmost 1 bit to 0                   +   x & (x - 1)                      +   100101000 -> 100100000
 * Remove all bits to the left of the first 1     +   x & (x ^ (x - 1)) or x & (-x)    +   100101000 -> 1000
 * Remove the last bit                            +   x >> 1                           +   101101 -> 10110
 * Get the k-th bit from the right                +   x >> (k - 1) & 1                 +   1101101 -> 1, k = 4
 * Get the last 3 bits                            +   x & 7                            +   1101101 -> 101
 * Get the last k bits                            +   x & 15                           +   1101101 -> 1101, k = 4
 * Retain the rightmost consecutive 1 bits        +   (x ^ (x + 1)) >> 1               +   100101111 -> 1111
 * Flip the k-th bit from the right               +   x ^ (1 << (k - 1))               +   101001 -> 101101, k = 3
 * Add a 0 at the end                             +   x << 1                           +   101101 -> 1011010
 * Add a 1 at the end                             +   (x << 1) + 1                     +   101101 -> 1011011
 * Set the k-th bit from the right to 0           +   x & ~(1 << (k - 1))              +   101101 -> 101001, k = 3
 * Set the k-th bit from the right to 1           +   x | (1 << (k - 1))               +   101001 -> 101101, k = 3
 * Set the first 0 bit from the right to 1        +   x | (x + 1)                      +   100101111 -> 100111111
 * Set the consecutive 0 bits from the right to 1 +   x | (x - 1)                      +   11011000 -> 11011111
 * Set the consecutive 1 bits from the right to 0 +   x & (x + 1)                      +   100101111 -> 100100000
 * Set the last bit to 0                          +   x | 1 - 1                        +   101101 -> 101100
 * Set the last bit to 1                          +   x | 1                            +   101100 -> 101101
 * Set the last k bits to 1                       +   x | (1 << (k - 1))               +   101001 -> 101111, k = 4
 * Flip the last bit                              +   x ^ 1                            +   101101 -> 101100
 * Flip the last k bits                           +   x ^ (1 << (k - 1))               +   101001 -> 100110, k = 4
 */
