#include"sort.h"
#include <stdlib.h>
#include <string.h>

/**
 * merge_sort - Sorts an array of integers
 * @array: Pointer to the array of integers
 * @size: Size of the array
 */

void merge_sort(int *array, size_t size)
{
	size_t mid;
	int *righthalf, *lefthalf;

	if (array == NULL || size < 2)
		return;

	mid = size / 2;
	lefthalf = malloc(mid * sizeof(int));
	righthalf = malloc((size - mid) * sizeof(int));

	memcpy(lefthalf, array, mid * sizeof(int));
	memcpy(righthalf, array + mid, (size - mid) * sizeof(int));

	merge_sort(lefthalf, mid);
	merge_sort(righthalf, size - mid);

	merge(array, lefthalf, mid, righthalf, size - mid);

	free(lefthalf);
	free(righthalf);

}
/**
 * merge - Merges two sorted halves of an array into a single sorted array
 * @array: Pointer to the array of integers to be sorted
 * @lefthalf: Pointer to the left half
 * @left_size: Size of the left half
 * @righthalf: Pointer to the right half
 * @right_size: Size of the right half
 */
void merge(
	int *array, int *left, size_t left_size, int *right, size_t right_size)
{
	size_t i = 0, j = 0, k = 0;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(left, left_size);
	printf("[right]: ");
	print_array(right, right_size);

	while (i < left_size && j < right_size)
	{
		if (left[i] <= right[j])
			array[k++] = left[i++];
		else
			array[k++] = right[j++];
	}

	while (i < left_size)
	{
		array[k++] = left[i++];
	}

	while (j < right_size)
	{
		array[k++] = right[j++];
	}

	printf("[Done]: ");
	print_array(array, left_size + right_size);
}
