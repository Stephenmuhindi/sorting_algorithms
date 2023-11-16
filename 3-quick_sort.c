#include "sort.h"
#include <stdio.h>

/**
 * partition - takes an array, indices of the low and high elements
 * and the size of the array.
 *
 * @array: worked on array
 * @low: low iter
 * @high: high iter
 * @size: count
 * Return: count
 */
size_t partition(int **array, size_t low, size_t high, size_t size)
{
	size_t i, j;
	int temp, pivot;

	pivot = (*array)[high];
	i = low - 1;
	for (j = low; j < high; j++)
	{
		if ((*array)[j] <= pivot)
		{
			i++;
			temp = (*array)[i];
			(*array)[i] = (*array)[j];
			(*array)[j] = temp;
			if ((*array)[i] !=  (*array)[j])
				print_array(*array, size);
		}
	}

	temp =  (*array)[i + 1];
	(*array)[i + 1] = (*array)[high];
	(*array)[high] = temp;
	if ((*array)[i + 1] !=  (*array)[high])
		print_array(*array, size);
	return (i + 1);
}

/**
 * qS - recursive quicksort gets the pivot
 * @array: array yenyewe
 * @low: low count
 * @high: high count
 * @size: count
 * Return: void
 */
void qS(int **array, size_t low, size_t high, size_t size)
{
	size_t pi;

	if (low < high)
	{
		pi = partition(array, low, high, size);

		if (pi != 0)
			qS(array, low, (pi - 1), size);
		if (pi < size - 1)
			qS(array, (pi + 1), high, size);
	}
}

/**
 * quick_sort - sort alogarithm
 * @array: array
 * @size: count
 * Return: void
 */

void quick_sort(int *array, size_t size)
{
	if (size > 1)
		qS(&array, 0, (size - 1), size);
}
