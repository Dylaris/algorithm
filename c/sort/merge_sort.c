#include <stdio.h>

/*
 * NAME
 ** Merge
 *
 * PURPOSE
 ** Merges two sorted subarrays into a single sorted array. This is a
 ** key operation used in the Merge Sort algorithm.
 *
 * PSEUDO-CODE
 ** SET p to first element of an array
 ** SET q to first element of another array
 ** SET idx to first element of result array, which stored merged result
 ** CREATE an empty temporary array res
 ** WHILE p is within the left subarray AND q is within the right subarray:
 **   IF arr[p] <= arr[q]:
 **     APPEND arr[p] to res
 **     p = p + 1
 **   ELSE:
 **     APPEND arr[q] to res
 **     q = q + 1
 ** AFTER merging:
 **   WHILE p is within the left subarray:
 **     APPEND arr[p] to res
 **     p = p + 1
 ** AFTER merging:
 **   WHILE q is within the right subarray:
 **     APPEND arr[q] to res
 **     q = q + 1
 ** COPY the sorted elements from res back to arr
 *
 * COST
 ** time:  O(n)
 ** space: O(n)
 */

static void merge(int arr[], size_t left, size_t mid, size_t right)
{
    int p = left, q = mid + 1;
    int idx = 0;
    int res[right - left + 1];

    while (p <= mid && q <= right) {
        if (arr[p] <= arr[q])
            res[idx++] = arr[p++];
        else
            res[idx++] = arr[q++];
    }

    while (p <= mid) res[idx++] = arr[p++];
    while (q <= right) res[idx++] = arr[q++];

    for (int i = left; i <= right; i++)
        arr[i] = res[i - left];
}

/*
 * NAME
 ** Merge Sort
 *
 * PURPOSE
 ** Sorts an array using the Merge Sort algorithm. Merge Sort is a divide 
 ** and conquer algorithm that divides the array into halves, recursively sorts 
 ** each half, and merges them back together in sorted order.
 *
 * PSEUDO-CODE
 ** IF left >= right:
 **   RETURN (array is already sorted)
 ** mid = (left + right) / 2
 ** RECURSIVELY sort the left half (left, mid)
 ** RECURSIVELY sort the right half (mid + 1, right)
 ** MERGE the sorted halves (left, mid, right)
 *
 * COST
 ** time:  O(n log n)
 ** space: O(n)
 */
static void merge_sort(int arr[], size_t left, size_t right)
{
    if (left >= right) return;

    size_t mid = (left + right) / 2;
    merge_sort(arr, left, mid);
    merge_sort(arr, mid + 1, right);
    merge(arr, left, mid, right);
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

    merge_sort(arr, 0, size - 1);
    print(arr, size);

    return 0;
}
