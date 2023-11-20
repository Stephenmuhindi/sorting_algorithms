#include "sort.h"
#include <stdio.h>

/**
 * partition - This function takes the last element of the array
 * as a pivot and
 * partitions the array into two parts such that elements smaller
 * than the pivot are on the left, and elements greater than the pivot
 * are on the right. It then returns the index of the pivot.
 *
 * @array: The array to be sorted.
 * @low: The starting index of the partition.
 * @high: The ending index of the partition.
 * @size: The size of the array.
 * Return: The index of the pivot.
 */
size_t partition(int **array, size_t low, size_t high, size_t size)
{
	int pivot = (*array)[high];
	int i = low - 1, j = high + 1, temp;

	while (i < j)
	{
		do {
			i++;
		} while ((*array)[i] < pivot);

		do {
			j--;
		} while ((*array)[j] > pivot);

		if (i < j)
		{
			temp = (*array)[i];
			(*array)[i] = (*array)[j];
			(*array)[j] = temp;
			print_array(*array, size);
		}
	}
	return (i);
}

/**
 * qS - This function recursively applies the quicksort algorithm sorts
 * array using the Hoare partition scheme. It chooses a pivot, partitions
 * the array, and then recursively applies the algorithm to the two sub-arrays.
 * @array: sort array
 * @low: start index
 * @high: end index
 * @size: bytes
 * Return: void.
 */
void qS(int **array, size_t low, size_t high, size_t size)
{
	size_t pi;

	if (low < high)
	{
		pi = partition(array, low, high, size);

		qS(array, low, (pi - 1), size);
		qS(array, pi, high, size);
	}
}

/**
 * quick_sort_hoare - This function initiates the quicksort
 * algorithm using the Hoare partition
 * scheme on the given array. If the size of the array is
 * greater than 1,
 * it calls the qS function to perform the sorting.
 * @array: sort array.
 * @size: bytes
 * Return: Nothing.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (size > 1)
		qS(&array, 0, (size - 1), size);
}
