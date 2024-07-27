#include "sort.h"

/**
 * selection_sort - sorting algorithm
 * @array: array to be sorted
 * @size: size of array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_index;
	int temp;

	for (i = 0; i < size; i++)
	{
		min_index = i;
		for (j = i; j < size; j++)
		{
			if (array[min_index] > array[j])
				min_index = j;
		}
		if (min_index != i)
		{
			temp = array[min_index];
			array[min_index] = array[i];
			array[i] = temp;
			print_array(array, size);
		}
	}
}
