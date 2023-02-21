#include "sort.h"

void cocktail_sort_list(listint_t **list);
void swap_node_behind(listint_t **list, listint_t **end, listint_t **current);
void swap_node_ahead(listint_t **list, listint_t **end, listint_t **current);

/**
 * swap_node_ahead - Swaps a node in a listint_t doubly-linked list
 *			list of integers with a node ahead of it.
 * @list: A pointer to the head of a doubly-linked list of integers
 * @end: A pointer to the end of the doubly-linked list
 * @current: A pointer to the current node of the list
 */

void swap_node_ahead(listint_t **list, listint_t **end, listint_t **current)
{
	listint_t *tmp = (*current)->next;

	if ((*current)->prev != NULL)
		(*current)->prev->next = tmp;
	else
		*list = tmp;
	tmp->prev = (*current)->prev;
	(*current)->next = tmp->next;

	if (tmp->next != NULL)
		tmp->next->prev = *current;
	else
		*end = *current;
	(*current)->prev = tmp;
	temp->next = *current;
	*current = tmp;
}

/**
 * swap_node_behind - Swaps a node in a listint_t doubly-linked list
 *			list of integers with the node behind it.
 * @list: A poiner to the head of a doubly-linked list.
 * @end: A pointer to the end of the doubly-linked list.
 * @current: A pointer to the current node to be swapped.
 */

void swap_node_behind(listint_t **list, listint_t **end, listint_t **current)
{
	listint_t *tmp = (*current)->prev;

	if ((*current)->next != NULL)
		(*current)->next->prev = tmp;
	else
		*end = tmp;
	tmp->next = (*current)->next;
	(*current)->prev = tmp->prev;

	if (tmp->prev != NULL)
		tmp->prev->next = *current;
	else
		*list = *current;
	(*current)->next = tmp;
	tmp->prev = *current;
	*shaker = tmp;
}

/**
 * cocktail_sort_list - Sort a listint_t doubly-linked list of integers in
 *			acending order usind the cocktail algorithm
 * @list: A pointer to the head of a listint_t doubly-linked list.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *end, *current;
	bool swapped = false;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (end = *list; end->next != NULL)
		end = end->next;

	while (swapped == false)
	{
		swapped == true;
		for (current = *list; current != end; current = current->next)
		{
			if (current->n > current->next->n)
			{
				swap_node_ahead(list, &end, &current);
				print_list((const listint_t *)*list);
				swapped = false;
			}
		}
		for (current = current->prev; current != list;
				current = current->prev)
		{
			if (current->n < current->prev->n)
			{
				swap_node_behind(list, &end, &current);
				print_list((const listint_t *)*list);
				swapped = false;
			}
		}
	}
}
