#include "sort.h"

/**
 * swap - swaps two adjacent nodes in a doubly linked list.
 * @list: pointer to a pointer to the head of the list.
 * @prevnode: pointer to a pointer to the previous node of the current node.
 * @curnode: pointer to the current node to be moved.
 */
void swap(listint_t **list, listint_t **prevnode, listint_t *curnode)
{
	(*prevnode)->next = curnode->next;
	if (curnode->next != NULL)
		curnode->next->prev = *prevnode;

	curnode->prev = (*prevnode)->prev;
	curnode->next = *prevnode;

	if ((*prevnode)->prev != NULL)
		(*prevnode)->prev->next = curnode;
	else
		*list = curnode;

	(*prevnode)->prev = curnode;
	*prevnode = curnode->prev;
}

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * using Insertion Sort.
 * @list: pointer to a pointer to the head of the list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curnode, *prevnode, *nextnode;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (curnode = (*list)->next; curnode != NULL; curnode = nextnode)
	{
		nextnode = curnode->next;
		prevnode = curnode->prev;

		while (prevnode != NULL && prevnode->n > curnode->n)
		{
			swap(list, &prevnode, curnode);
			print_list((const listint_t *)*list);
		}
	}
}

