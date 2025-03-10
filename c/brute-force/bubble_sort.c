/*
pseudo-code:
    for i <- n-1 downto 1 do
        for j <- 0 to i-1 do
            if arr[j] > arr[j+1] then
                swap(j, j+1)
 */

#include <stdio.h>

static void bubble_sort(int arr[], size_t size)
{
    for (size_t i = size - 1; i > 0; i--) {
        for (size_t j = 0; j < i; j++) {
            if (arr[j] > arr[j + 1]) {
                /* swap */
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
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
    int arr[] = {2, 4, 1, -9, 8, 3, -7};
    size_t size = sizeof(arr) / sizeof(arr[0]);
    print(arr, size);

    bubble_sort(arr, size);
    print(arr, size);

    return 0;
}