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
