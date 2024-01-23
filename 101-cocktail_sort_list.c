#include "sort.h"
/**
 * list_len - function returns length of list
 * @list: head of list
 * Return: length
 */
size_t custom_list_len(listint_t *list)
{
	size_t len = 0;

	while (list)
	{
		len++;
		list = list->next;
	}
	return (len);
}
/**
 * switch_nodes - function swaps nodes at pointer current with the following node
 * @list: head of list
 * @current: pointer to node
 */
void custom_switch_nodes(listint_t **list, listint_t **current)
{
	listint_t *prev_node, *current_node, *next_node, *next_next_node;

	prev_node = (*current)->prev;
	current_node = *current;
	next_node = (*current)->next;
	next_next_node = (*current)->next->next;
	current_node->next = next_next_node;
	if (next_next_node)
		next_next_node->prev = current_node;
	next_node->next = current_node;
	next_node->prev = current_node->prev;
	if (prev_node)
		prev_node->next = next_node;
	else
		*list = next_node;
	current_node->prev = next_node;
	*current = next_node;
}
/**
 * cocktail_sort_list - function sorts a doubly linked list using
 * the cocktail sort algorithm
 * @list: pointer to list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *current_node;
	int sorted = 0;
	if (!list || !*list || custom_list_len(*list) < 2)
		return;
	current_node = *list;
	while (!sorted)
	{
		sorted = 1;
		while (current_node->next)
		{
			if (current_node->n > current_node->next->n)
			{
				sorted = 0;
				custom_switch_nodes(list, &current_node);
				print_list(*list);
			}
			else
				current_node = current_node->next;
		}
		if (sorted)
			break;
		current_node = current_node->prev;
		while (current_node->prev)
		{
			if (current_node->n < current_node->prev->n)
			{
				sorted = 0;
				current_node = current_node->prev;
				custom_switch_nodes(list, &current_node);
				print_list(*list);
			}
			else
				current_node = current_node->prev;
		}
	}
}
