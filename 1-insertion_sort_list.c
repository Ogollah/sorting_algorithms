#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list.
 * @list: Pointer to the head of the list.
 * @node1: First node to swap.
 * @node2: Second node to swap.
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	if (node1->prev)
		node1->prev->next = node2;
	if (node2->next)
		node2->next->prev = node1;

	node1->next = node2->next;
	node2->prev = node1->prev;
	node1->prev = node2;
	node2->next = node1;

	if (node1->prev == NULL)
		*list = node1;
	if (node2->prev == NULL)
		*list = node2;
}

/**
 * insertion_sort_list - Sorts a doubly linked list of
 *                       integers in ascending order using Insertion sort.
 * @list: Pointer to the head of the list.
 */
void insertion_sort_list(listint_t **list)
{
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	listint_t *curr = (*list)->next;

	while (curr != NULL)
	{
		listint_t *insertion_point = curr->prev;

		while (insertion_point != NULL && curr->n < insertion_point->n)
		{
			swap_nodes(list, insertion_point, curr);
			insertion_point = curr->prev;
			print_list(*list);
		}
		curr = curr->next;
	}
}
