#include <stdio.h>

/*
 * NAME
 ** selection_sort
 *
 * PURPOSE
 ** Sorts an array using the Selection Sort algorithm. Selection Sort is an 
 ** in-place, comparison-based sorting algorithm. It works by repeatedly 
 ** selecting the smallest (or largest) element from the unsorted part of the 
 ** array and swapping it with the element at the current position.
 *
 * PSEUDO-CODE
 ** FOR i from first element to last second element:
 **     FOR j from element after i to last element:
 **         IF arr[j] < arr[min_idx]: min_idx = j
 **     SWAP arr[i] and arr[min_idx]
 *
 * COST
 ** time:  O(n^2) for both best, average, and worst cases
 ** space: O(1) for in-place sorting
 */

static void selection_sort(int arr[], size_t size)
{
    int min_idx = 0;
    for (size_t i = 0; i < size - 1; i++) {
        for (size_t j = i; j < size; j++) {
            if (arr[min_idx] > arr[j]) {
                min_idx = j;
            }
        }
        /* swap */
        int tmp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = tmp;
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
    int arr[] = {4, 5, 7, -1, 2, 4, 0};
    size_t size = sizeof(arr) / sizeof(arr[0]);
    print(arr, size);

    selection_sort(arr, size);
    print(arr, size);

    return 0;
}