#include "sort.h"
#include <stdio.h>

/**
 * merge_compare - Merge two sorted subarrays
 * @array:  array to sort.
 * @start: start index
 * @stop:  stop index
 * @new: output array to store
 * This function compares and merges two sorted subarrays within
 * the given array.
 * It prints the subarrays before and after merging for visualization.
 */
void merge_compare(int *array, size_t start, size_t stop, int *new)
{
	size_t i = start, j, k, mid;

	j = mid = (start + stop) / 2;
	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + start, mid - start);
	printf("[right]: ");
	print_array(array + mid, stop - mid);
	for (k = start; k < stop; k++)
		if (i < mid && (j >= stop || array[i] <= array[j]))
		{

			new[k] = array[i++];
		}
		else
		{
			new[k] = array[j++];
		}
	printf("[Done]: ");
	print_array(new + start, stop - start);
}

/**
 * merge_sort_top_down - Recursive top-down merge sort.
 * @array: int array
 * @start: start index
 * @stop: stop index
 * @new: aux
 *
 * This function recursively divides the array
 * into subarrays and merges them in sorted order.
 */
void merge_sort_top_down(int *array, size_t start, size_t stop, int *new)
{
	size_t mid;

	mid = (start + stop) / 2;
	if (stop - start < 2)
	{
		return;
	}
	merge_sort_top_down(new, start, mid, array);
	merge_sort_top_down(new, mid, stop, array);
	merge_compare(new, start, stop, array);
}


/**
 * merge_sort - Sorts an array.
 * @array: list of int
 * @size: array bytes
 * Return: void
 * This function initializes the auxiliary array,
 * calls the top-down merge sort function.
 * It also frees the auxiliary array after sorting.
 */
void merge_sort(int *array, size_t size)
{
	int *new;
	size_t i;


	if (!array || size < 2)
		return;

	new = malloc(sizeof(int) * size);
	if (!new)
		return;
	for (i = 0; i < size; i++)
		new[i] = array[i];
	merge_sort_top_down(array, 0, size, new);
	free(new);
}
