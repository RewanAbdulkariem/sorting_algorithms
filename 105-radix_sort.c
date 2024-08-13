#include"sort.h"
#include <stdlib.h>
#include <string.h>
/**
 * radix_sort - Sorts an array of integers
 * @array: Pointer to the array of integers
 * @size: Size of the array
 */
void radix_sort(int *array, size_t size)
{
	int exp, max;

	if (size < 2)
	{
		return;
	}
	max = get_max(array, size);

	for (exp = 1; max / exp > 0; exp *= 10)
	{
		count_sort(array, size, exp);
		print_array(array, size);
	}
}
/**
 * get_max - Sorts an array of integers
 * @array: Pointer to the array of integers
 * @size: Size of the array
 */
int get_max(int *arr, size_t size)
{
	int max;
	size_t i;

	max = arr[0];
	for (i = 1; i < size; i++)
		if (arr[i] > max)
			max = arr[i];
	return (max);
}
/**
 * count_sort - Sorts an array of integers
 * in ascending order using Counting sort algorithm
 * @array: Pointer to the array of integers
 * @size: Size of the array
 * @exp: exponent
 */
void count_sort(int *array, size_t size, int exp)
{
	size_t i;
	int *output;
	int count[10] = {0};

	output = malloc(size * sizeof(int));

	for (i = 0; i < size; i++)
	{
		count[(array[i] / exp) % 10]++;
	}

	for (i = 1; i < 10; i++)
	{
		count[i] += count[i - 1];
	}

	for (i = size; i > 0; i--)
	{
		output[count[(array[i - 1] / exp) % 10] - 1] = array[i - 1];
		count[(array[i - 1] / exp) % 10]--;
	}

	memcpy(array, output, size * sizeof(int));

	free(output);
}
