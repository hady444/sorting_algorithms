#include "sort.h"
/**
 * insertion_sort_list - sorts a doubly list in order using the Insertion sort
 * @list: list of nodes to be sorted
 *
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *node, *now;

	if (!list || *list == NULL)
		return;
	node = (*list);
	now = node->next;
	while (now)
	{
		node = now;
		now = now->next;
		while (node)
		{
			if (node->n < node->prev->n)
			{
				node->prev->next = node->next;
				if (node->next)
					node->next->prev = node->prev;
				node->next = node->prev;
				if (node->prev->prev)
					node->prev->prev->next = node;
				node->prev = node->prev->prev;
				if (node->next)
					node->next->prev = node;
				if (node->prev == NULL)
				{
					*list = node;
					print_list(*list);
					break;
				}
				print_list(*list);
			}
			else
				break;
		}
	}
}
