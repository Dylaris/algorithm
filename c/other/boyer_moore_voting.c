/*
 * NAME
 ** Boyer-Moore Voting
 *
 * PURPOSE
 ** Used to solve the majority element problem, where the goal is to find the
 ** element that appears more than half the time in an array.
 * 
 * PSEUDO-CODE
 ** candidate = None
 ** count = 0
 ** FOR each element IN array:
 **   IF count == 0:
 **     candidate = element
 **   IF candidate == element:
 **     count = count + 1
 **   ELSE:
 **     count = count - 1
 ** RETURN candidate
 *
 * COST
 ** time:  O(n)
 ** space: O(1)
 */

#include <stdio.h>

static int boyer_moore_voting(int nums[], size_t size)
{
    int candidate = -1;
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (count == 0) candidate = nums[i];
        if (candidate == nums[i]) count++;
        else count--;
    }
    return candidate;
}

int main(void)
{
    int nums[] = {1, 1, 1, 1, 4, 5, 6};
    printf("majority element: %d\n", boyer_moore_voting(nums, sizeof(nums)/sizeof(int)));
    return 0;
}
