/*
 * Useful bitwise operations.
 */

/*
 * LOWBIT(x): Extracts the lowest set bit of x.
 * Example: x = 12 (binary: 1100), LOWBIT(12) = 4 (binary: 0100)
 * This operation isolates the lowest set bit.
 */
#define LOWBIT(x)           (x & -x)

/* 
 * RESET_LOWEST_ONE(x): Clears the lowest set bit of x.
 * Example: x = 12 (binary: 1100), RESET_LOWESE_ONE(12) = 8 (binary: 1000)
 * This operation removes the lowest 1-bit from x.
 */
#define RESET_LOWEST_ONE(x) (x & (x - 1))