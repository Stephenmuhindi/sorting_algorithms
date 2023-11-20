#include "sort.h"
#include <stdlib.h>

/**
 * counting_sort - sorts an array
 * @array: array
 * @size: array size
 * This function takes an array of non-negative integers and sorts them
 * in ascending order using the Counting sort algorithm. It first identifies
 * the maximum value in the array, allocates a counting array to store the
 * frequency of each element, and then modifies the counting array to store
 * the cumulative count. After printing the counting array, it uses this
 * information to create a sorted array. Finally, the original array is
 * updated with the sorted values, and memory allocated for counting_array
 * and sorted_array is freed.
 * Return: void
 */
void counting_sort(int *array, size_t size)
{
	unsigned long i;
	int j, max = 0;
	int *count_array, *sorted_array;
	/* Check if array is NULL or has fewer than 2 elements */
	if (array == NULL || size < 2)
		return;
	/* Find the maximum value in the array */
	for (i = 0; i < size; i++)
		if (array[i] > max)
			max = array[i];
	/* Allocate memory for the counting array */
	count_array = calloc(max + 1, sizeof(int));
	if (!count_array)
		return;
	/* Count the occurrences of each element in the array */
	for (i = 0; i < size; i++)
		count_array[array[i]] += 1;
	/* Modify the counting array to store cumulative count */
	for (j = 1; j < max + 1; j++)
		count_array[j] += count_array[j - 1];
	print_array(count_array, max + 1);
	sorted_array = malloc(size * sizeof(int));
	if (!sorted_array)
	{
		free(count_array);
		return;
	}
	/* Create the sorted array using cumulative count information */
	for (j = size - 1; j >= 0; j--)
	{
		i = count_array[array[j]];
		sorted_array[i - 1] = array[j];
		count_array[array[j]] -= 1;
	}
	/* Update the original array with sorted values */
	for (i = 0; i < size; i++)
		array[i] = sorted_array[i];
	/* Free allocated memory */
	free(count_array);
	free(sorted_array);
}
