#ifndef SORT_H_
#define SORT_H_

#include <stddef.h>
#include <stdlib.h>


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

void print_list(const listint_t *list);
void print_array(const int *array, size_t size);
void bubble_sort(int *array, size_t size);
void swap(listint_t **list, listint_t *current, listint_t *previous);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
size_t partition(int **array, size_t low, size_t high, size_t size);
void qS(int **array, size_t low, size_t high, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
int max_swap(listint_t **current, listint_t **previous,
		listint_t **head, listint_t **tail);
int min_swap(listint_t **current, listint_t **previous,
		listint_t **head, listint_t **tail);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void merge_compare(int *array, size_t start, size_t stop, int *new);
void merge_sort_top_down(int *array, size_t start, size_t stop, int *new);
void merge_sort(int *array, size_t size);
void siftDown(int *array, size_t start, size_t end, size_t size);
void heapify(int *array, size_t size);
void heap_sort(int *array, size_t size);
int getMax(int *array, size_t size);
void countingSort(int *arr, size_t n, int place);
void radix_sort(int *array, size_t size);
size_t partition(int **array, size_t low, size_t high, size_t size);
void qS(int **array, size_t low, size_t high, size_t size);
void quick_sort_hoare(int *array, size_t size);

#endif
