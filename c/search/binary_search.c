#include <stdio.h>

/*
 * NAME
 ** binary_search
 *
 * PURPOSE
 ** Searches for a target value in a sorted array using the Binary Search 
 ** algorithm. Binary Search is a divide-and-conquer algorithm that works by 
 ** repeatedly dividing the search interval in half. It compares the target 
 ** value to the middle element of the array. If the target value is smaller 
 ** than the middle element, the search continues in the left half; if larger, 
 ** it continues in the right half. The process repeats until the target is found 
 ** or the search interval is empty.
 *
 * PSEUDO-CODE
 ** SET left to the first element
 ** SET right to the last element
 ** WHILE left <= right:
 **   mid = left + (right - left) / 2
 **   IF arr[mid] < target:
 **     left = mid + 1
 **   ELSE IF arr[mid] > target:
 **     right = mid - 1
 **   ELSE:
 **     RETURN mid
 ** RETURN -1
 *
 * COST
 ** time:  O(log n) for best, average, and worst cases
 ** space: O(1) for in-place searching (constant space)
 */

static int binary_search(int arr[], size_t n, int target)
{
    size_t left = 0, right = n - 1;
    size_t mid;
    while (left <= right) {
        mid = left + (right - left) / 2;
        if (arr[mid] < target)
            left = mid + 1;
        else if (arr[mid] > target)
            right = mid - 1;
        else
            return mid;
    }
    return -1;
}

static void print(int arr[], size_t size)
{
    for (size_t i = 0; i < size; i++)
        printf(" %d", arr[i]);
    printf("\n");
}

int main(void)
{
    int arr[] = {-1, 2, 3, 4, 6, 7, 9};
    size_t size = sizeof(arr) / sizeof(arr[0]);
    print(arr, size);

    printf("target: %d\nindex: %d\n", 6, binary_search(arr, size, 6));
    printf("target: %d\nindex: %d\n", 5, binary_search(arr, size, 5));

    return 0;
}
