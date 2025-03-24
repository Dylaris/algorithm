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
