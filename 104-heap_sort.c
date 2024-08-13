#include"sort.h"
#include <stdlib.h>
/**
 * heap_sort - Sorts an array of integers
 * @array: Pointer to the array of integers
 * @size: Size of the array
 */
void heap_sort(int *array, size_t size)
{
	size_t i;
	int temp;

	if (array == NULL || size < 2)
		return;

	for (i = size / 2; i > 0; i--)
		sift_down(array, size, i - 1, size);
	sift_down(array, size, 0, size);

	for (i = size - 1; i > 0; i--)
	{
		temp = array[0];
		array[0] = array[i];
		array[i] = temp;

		print_array(array, size);
		sift_down(array, size, 0, i);
	}
}

/**
 * sift_down - Restores the heap property by moving the element at index `i`
 * down the heap.
 * @array: The array representing the heap.
 * @size: The size of the heap.
 * @i: The index of the element to sift down.
 * @heap_size: The size of the heap (i.e., the number of elements in the heap).
 */
void sift_down(int *array, size_t size, size_t i, size_t heap_size)
{
	size_t largest = i;
	size_t left = 2 * i + 1;
	size_t right = 2 * i + 2;
	int temp;

	if (left < heap_size && array[left] > array[largest])
		largest = left;

	if (right < heap_size && array[right] > array[largest])
		largest = right;

	if (largest != i)
	{
		temp = array[i];
		array[i] = array[largest];
		array[largest] = temp;

		print_array(array, size);
		sift_down(array, size, largest, heap_size);
	}
}
