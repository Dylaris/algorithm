#include <stdio.h>

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