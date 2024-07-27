#include"sort.h"
#include <stdlib.h>
/**
 * counting_sort - 
 * @array:
 * @size:
 */
void counting_sort(int *array, size_t size)
{
    size_t i;
    int max, *counting_arr, *output_array;

    max = array[0];
    for (i = 0; i < size; i++)
    {
        if (array[i] > max)
            max = array[i];
    }

    counting_arr = malloc((max + 1) * sizeof(int));
    output_array = malloc(size * sizeof(int));

    if (counting_arr == NULL)
        return;

    for (i = 0; i <= (size_t)max; i++)
        counting_arr[i] = 0;

    for (i = 0; i < size; i++)
        counting_arr[array[i]]++;

    for (i = 1; i <= (size_t)max; i++)
        counting_arr[i] += counting_arr[i-1];
    /* Print the counting array */
    for (i = 0; i <= (size_t)max; i++)
    {
        if (i > 0)
            printf(", ");
        printf("%d", counting_arr[i]);
    }
    printf("\n");

    for (i = 0; i < size; i++)
    {
        output_array[counting_arr[array[i]] - 1] = array[i];
        counting_arr[array[i]]--;
    }
    for (i = 0; i < size; i++)
        array[i] = output_array[i];
    free(counting_arr);
    free(output_array);
}