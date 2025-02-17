#ifndef SORT_H
#define SORT_H

/* ----headers----- */
#include <stdio.h>
#include <stddef.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/* ----PROTOTYPE----- */
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void swap_nodes(listint_t **list, listint_t *left, listint_t *right);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void quick_sort_helper(int *array, int low, int high, size_t size);
int partition(int *array, int low, int high, size_t size);
void swap(int *a, int *b);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void merge(int *array, int *lefthalf, size_t left_size,
	int *righthalf, size_t right_size);

void heap_sort(int *array, size_t size);
void sift_down(int *array, size_t size, size_t i, size_t heap_size);
void radix_sort(int *array, size_t size);
void count_sort(int *array, size_t size, int exp);
int get_max(int *arr, size_t size);
#endif
