#include <stdio.h>

void selection_sort(int array[], int size);

int main(void)
{
    int nums[] = {10, 100, 1000, 123, 3, 2, 1};
    selection_sort(nums, 7);
    return 0;
}

void selection_sort(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        int index_min = i;
        for (int j = i; j < size; j++)
        {
            if (array[j] < array[index_min])
            {
                index_min = j;
            }
        }
        int tmp = array[i];
        array[i] = array[index_min];
        array[index_min] = tmp;   
    }

    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}