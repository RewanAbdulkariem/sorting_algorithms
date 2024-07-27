#include "sort.h"

/**
 * insertion_sort_list -  Sorts a doubly linked list using insertion sort
 * @list: Pointer to the pointer of the head node of the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *next_node;

	if (!list || !(*list) || !(*list)->next)
		return;

	current = (*list)->next;
	while (current)
	{
		next_node = current->next;
		while (current->prev && current->prev->n > current->n)
		{
			swap_nodes(list, current->prev, current);
		}
		current = next_node;
	}
}
/**
 * swap_nodes - Swap two nodes in a doubly linked list
 * @list: Pointer to the head of the list
 * @left: Pointer to the left node
 * @right: Pointer to the right node
 */
void swap_nodes(listint_t **list, listint_t *left, listint_t *right)
{
	if (!left || !right || left == right)
		return;

	if (left->prev)
		left->prev->next = right;
	else
		*list = right;

	if (right->next)
		right->next->prev = left;

	left->next = right->next;
	right->prev = left->prev;
	left->prev = right;
	right->next = left;

	print_list(*list);
}
