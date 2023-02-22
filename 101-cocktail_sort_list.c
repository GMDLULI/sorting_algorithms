#include "sort.h"

void cocktail_sort_list(listint_t **list);
void swap_node_behind(listint_t **list, listint_t **end, listint_t **current);
void swap_node_ahead(listint_t **list, listint_t **end, listint_t **current);

/**
 * swap_node_ahead - Swaps a node in a listint_t doubly-linked list
 *			list of integers with a node ahead of it.
 * @list: A pointer to the head of a doubly-linked list of integers
 * @end: A pointer to the end of the doubly-linked list
 * @shaker: A pointer to the current swapping node of the list
 */

void swap_node_ahead(listint_t **list, listint_t **end, listint_t **shaker)
{
	listint_t *tmp = (*shaker)->next;

	if ((*shaker)->prev != NULL)
		(*shaker)->prev->next = tmp;
	else
		*list = tmp;
	tmp->prev = (*shaker)->prev;
	(*shaker)->next = tmp->next;

	if (tmp->next != NULL)
		tmp->next->prev = *shaker;
	else
		*end = *shaker;
	(*shaker)->prev = tmp;
	tmp->next = *shaker;
	*shaker = tmp;
}

/**
 * swap_node_behind - Swaps a node in a listint_t doubly-linked list
 *			list of integers with the node behind it.
 * @list: A poiner to the head of a doubly-linked list.
 * @end: A pointer to the end of the doubly-linked list.
 * @shaker: A pointer to the current node to be swapped.
 */

void swap_node_behind(listint_t **list, listint_t **end, listint_t **shaker)
{
	listint_t *tmp = (*shaker)->prev;

	if ((*shaker)->next != NULL)
		(*shaker)->next->prev = tmp;
	else
		*end = tmp;
	tmp->next = (*shaker)->next;
	(*shaker)->prev = tmp->prev;

	if (tmp->prev != NULL)
		tmp->prev->next = *shaker;
	else
		*list = *shaker;
	(*shaker)->next = tmp;
	tmp->prev = *shaker;
	*shaker = tmp;
}

/**
 * cocktail_sort_list - Sort a listint_t doubly-linked list of integers in
 *			acending order usind the cocktail algorithm
 * @list: A pointer to the head of a listint_t doubly-linked list.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *end, *shaker;
	bool swapped = false;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (end = *list; end->next != NULL;)
		end = end->next;

	while (swapped == false)
	{
		swapped == true;
		for (shaker = *list; shaker != end; shaker = shaker->next)
		{
			if (shaker->n > shaker->next->n)
			{
				swap_node_ahead(list, &end, &shaker);
				print_list((const listint_t *)*list);
				swapped = false;
			}
		}
		for (shaker = shaker->prev; shaker != *list;
				shaker = shaker->prev)
		{
			if (shaker->n < shaker->prev->n)
			{
				swap_node_behind(list, &end, &shaker);
				print_list((const listint_t *)*list);
				swapped = false;
			}
		}
	}
}
