#include <stdio.h>

/*
 * NAME
 ** Partition
 *
 * PURPOSE
 ** Partitions the array around a pivot element such that all elements 
 ** less than the pivot are to the left of it, and all elements greater 
 ** than the pivot are to the right. This function is used in the Quick 
 ** Sort algorithm to divide the array into smaller subarrays.
 *
 * PSEUDO-CODE
 ** SET pivot as the first element of the array
 ** WHILE left <= right:
 **   WHILE lefet < right AND arr[left] <= pivot: left = left + 1
 **   arr[left] = arr[right]
 **   WHILE left < right AND arr[right] >= pivot: right = right - 1
 **   arr[right] = arr[left]
 ** arr[left] = privot
 ** RETURN the index of the pivot
 *
 * COST
 ** time:  O(n)
 ** space: O(1)
 */

static size_t partition(int arr[], size_t left, size_t right)
{
    int pivot = arr[left];
    while (left < right) {
        while (left < right && arr[right] >= pivot) right--;
        arr[left] = arr[right];
        while (left < right && arr[left] <= pivot) left++;
        arr[right] = arr[left];
    }
    arr[left] = pivot;
    return left;
}

/*
 * NAME
 ** Quick Sort
 *
 * PURPOSE
 ** Sorts an array using the Quick Sort algorithm. Quick Sort is a divide 
 ** and conquer algorithm that works by partitioning the array into two subarrays, 
 ** recursively sorting each subarray, and combining the results. The partition 
 ** operation is key to dividing the array.
 *
 * PSEUDO-CODE
 ** IF left >= right:
 **     RETURN
 ** CALL partition to divide the array into two subarrays
 ** RECURSIVELY sort the left subarray (left to mid - 1)
 ** RECURSIVELY sort the right subarray (mid + 1 to right)
 *
 * COST
 ** time:  O(n log n) on average, O(n^2) in the worst case
 ** space: O(log n) for recursion stack
 */

static void quick_sort(int arr[], size_t left, size_t right)
{
    if (left >= right) return;

    size_t mid = partition(arr, left, right);
    quick_sort(arr, left, mid - 1);
    quick_sort(arr, mid + 1, right);
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

    quick_sort(arr, 0, size - 1);
    print(arr, size);

    return 0;
}
