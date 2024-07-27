#include"sort.h"
/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in ascending
 * @list: Pointer to the head of the doubly linked list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *start, *end;
	int swapped;

	if (!list || !(*list) || !(*list)->next)
		return;

	end = NULL;
	start = *list;
	swapped = 1;

	while (swapped)
	{
		swapped = 0;
		while (start->next && start->next != end)
		{
			if (start->n > start->next->n)
			{
				swap_nodes(list, start, start->next);
				swapped = 1;
			}
			else
				start = start->next;
		}
		if (!swapped)
			break;
		end = start;
		swapped = 0;
		while (end->prev && end->prev != start)
		{
			if (end->n < end->prev->n)
			{
				swap_nodes(list, end->prev, end);
				swapped = 1;
			}
			else
				end = end->prev;
		}
		start = *list;
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

	if (left->next)
		left->next->prev = left;

	if (right->prev)
		right->prev->next = right;

	print_list(*list);
}
