/*
 * NAME
 ** Bubble Sort
 *
 * PURPOSE
 ** Sorts an array of integers in ascending order using the Bubble Sort 
 ** algorithm. The algorithm repeatedly steps through the list, compares 
 ** adjacent elements, and swaps them if they are in the wrong order.
 * 
 * PSEUDO-CODE
 ** FOR i from last element down to second element:
 **     FOR j from first element to element before i:
 **         IF arr[j] > arr[j + 1]:
 **             SWAP arr[j] and arr[j + 1]
 *
 * COST
 ** time:  O(n^2)
 ** space: O(1)
 */

#include <stdio.h>

static void bubble_sort(int arr[], size_t size)
{
    for (size_t i = size - 1; i > 0; i--) {
        for (size_t j = 0; j < i; j++) {
            if (arr[j] > arr[j + 1]) {
                /* swap */
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

static void print(int arr[], size_t size)
{
    for (size_t i = 0; i < size; i++)
        printf(" %d", arr[i]);
    printf("\n");
}

int main(void)
{
    int arr[] = {2, 4, 1, -9, 8, 3, -7};
    size_t size = sizeof(arr) / sizeof(arr[0]);
    print(arr, size);

    bubble_sort(arr, size);
    print(arr, size);

    return 0;
}