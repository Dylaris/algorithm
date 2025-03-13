/*
binary_search:
  left <- 0
  right <- n-1
  while left <= right then
    mid <- left+(right-left)//2
    if arr[mid] < target then
      left = mid + 1
    else if arr[mid] > target then
      right = mid - 1
    else 
      return mid
  return -1
*/

#include <stdio.h>

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
