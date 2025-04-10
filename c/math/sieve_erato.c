/*
 * NAME
 ** Sieve of Eratosthenes
 *
 * PURPOSE
 ** Computes the number of prime numbers up to a given integer n 
 ** using the Sieve of Eratosthenes algorithm. This algorithm efficiently 
 ** finds all primes less than or equal to n.
 * 
 * PSEUDO-CODE
 **  prime = array of size (n+1) with all true
 **  prime[0] = false
 **  prime[1] = false
 **    FOR i from 2 to sqrt(n):
 **      IF prime[i] == true:
 **        FOR j from i*i to n step i:
 **          prime[j] = false
 **  count = 0
 **  FOR i from 2 to n:
 **    IF prime[i] == true:
 **      count = count + 1
 **  RETURN count
 *
 * COST
 ** time:  O(n log log n)
 ** space: O(n)
 */

#include <math.h>
#include <stdio.h>

static int sieve(int n)
{
    int prime[n + 1];
    for (int i = 0; i <= n; i++)
        prime[i] = 1;
    prime[0] = prime[1] = 0;

    for (int i = 2; i <= sqrt(n); i++)
        for (int j = i * i; j < n; j += i)
            prime[j] = 0;

    int count = 0;
    for (int i = 1; i <= n; i++)
        if (prime[i]) count++;

    return count;
}

int main(void)
{
    printf("prime (5): %d\n", sieve(5));

    return 0;
}