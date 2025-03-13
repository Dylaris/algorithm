/*
merge_sort(A):
  if numberof(A) > 1 then
    B <- A[0:n//2]
    C <- A[n//2:n]
    merge_sort(B)
    merge_sort(C)
    merge(B, C)
  
merge(B, C):
  p = 0 // 指向 B
  q = 0 // 指向 C
  i = 0 // 结果数组 res 的索引

  while p < len(B) && q < len(C) do
    if B[p] <= C[q] then
      res[i++] = B[p++] // 取 B 中较小的元素
    else 
      res[i++] = C[q++] // 取 C 中较小的元素

  if p < len(B) then
    copy(B[p:], res, i) // 复制 B 中剩余的元素到 A
  
  if q < len(C) then
    copy(C[q:], res, i) // 复制 C 中剩余的元素到 A
*/

#include <stdio.h>

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

static void merge_sort(int arr[], size_t left, size_t right)
{
    if (left < right) {
        size_t mid = (left + right) / 2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        merge(arr, left, mid, right);
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

    merge_sort(arr, 0, size - 1);
    print(arr, size);

    return 0;
}
