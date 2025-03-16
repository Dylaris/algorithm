/*
partition(arr)
  // 默认用第一个元素作为pivot
  pivot <- arr[0]
  lp <- 0
  rp <- n - 1
  while lp < rp do
    while lp < rp && arr[rp] >= pivot do
      rp--
    lp <- rp
    while lp < rp && arr[lp] < pivot do
      lp++
    rp <- lp

  pivot_idx <- lp
  arr[pivot_idx] <- pivot
  return pivot_idx // 这个就是分区界线

quick_sort(arr):
  limit <- partition(arr)
  quick_sort(arr[:limit-1])
  quick_sort(arr[limit+1:])
*/

#include <stdio.h>

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
