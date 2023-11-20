#include "sort.h"

/**
 * max_swap - Swaps a node with its next
 * node in a doubly linked list.
 * @current: Pointer to the current node.
 * @previous: Pointer to the previous node.
 * @head: Pointer to the head of the list.
 * @tail: Pointer to the tail of the list.
 * Return: Always returns 1.
 */
int max_swap(listint_t **current, listint_t **previous,
		listint_t **head, listint_t **tail)
{
	if ((*current)->next == NULL)
		*tail = *previous;
	if ((*previous)->prev == NULL)
		*head = *current;
	if ((*current)->next != NULL)
		(*current)->next->prev = *previous;
	if ((*previous)->prev != NULL)
		(*previous)->prev->next = *current;
	(*current)->prev = (*previous)->prev;
	(*previous)->next = (*current)->next;
	(*current)->next = *previous;
	(*previous)->prev = *current;
	*current = *previous;
	*previous = (*current)->prev;
	(void) tail;
	print_list(*head);
	return (1);
}

/**
 * min_swap - Swaps a node with its next
 * node in a doubly linked list.
 * @current: Pointer to the current node.
 * @previous: Pointer to the previous node.
 * @head: Pointer to the head of the list.
 * @tail: Pointer to the tail of the list.
 * Return: Always returns 1.
 */
int min_swap(listint_t **current, listint_t **previous,
		listint_t **head, listint_t **tail)
{
	if ((*current)->prev == NULL)
		*head = *previous;
	if ((*previous)->next == NULL)
		*tail = *current;
	if ((*current)->prev != NULL)
		(*current)->prev->next = *previous;
	if ((*previous)->next != NULL)
		(*previous)->next->prev = *current;
	(*current)->next = (*previous)->next;
	(*previous)->prev = (*current)->prev;
	(*current)->prev = *previous;
	(*previous)->next = *current;
	*current = *previous;
	*previous = (*current)->next;
	(void) tail;
	print_list(*head);
	return (1);
}

/**
 * cocktail_sort_list - Sorts a doubly linked list
 * using the Cocktail Shaker sort algorithm.
 * @list: Pointer to a pointer to the head of the list.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *current, *head, *previous, *tail;
	int swap = 1, direction = 1;

	if (list == NULL)
		return;
	if ((*list) == NULL || (*list)->next == NULL)
		return;
	head = *list;
	tail = NULL;
	while (swap)
	{
		swap = 0;
		if (direction == 1)
		{
			previous = head;
			current = head->next;
		}
		else
		{
			previous = tail;
			current = tail->prev;
		}
		while (current)
		{
			if (direction == 1 && current->n < previous->n)
				swap = max_swap(&current, &previous, &head, &tail);
			if (direction == 0 && current->n > previous->n)
				swap = min_swap(&current, &previous, &head, &tail);
			previous = current;
			if (direction == 1)
				current = current->next;
			else
				current = current->prev;
		}
		direction = !direction;
	}
	*list = head;
}
