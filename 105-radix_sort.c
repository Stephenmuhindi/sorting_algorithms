#include "sort.h"

/**
 * getMax - max element
 * @array: prov array
 * @size: array size
 * Return: max elem
 */
int getMax(int *array, size_t size)
{
	int max;
	size_t i;

	/* Initialize max with the first element of the array */
	max = *array;

	/* Iterate through the array to find the maximum element */
	for (i = 1; i < size; i++)
		if (array[i] > max)
			max = array[i];

	return (max);
}

/**
 * countingSort - counting sort on the array based on a specific place
 * @arr: sortarray
 * @n: array size
 * @place: place value.
 * Return: void
 */
void countingSort(int *arr, size_t n, int place)
{
	int *output, i, count[10] = { 0 };
	size_t j;

	/* Allocate memory for the output array */
	output = malloc(sizeof(int) * n);
	if (output == NULL)
		return;

	/* Count occurrences of digits at the specified place */
	for (j = 0; j < n; j++)
		count[(arr[j] / place) % 10]++;

	/* Modify count array to store actual position of the digits */
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	/* Build the output array by placing elements in their correct positions */
	for (j = 0; j < n; j++)
	{
		output[count[(arr[n - 1 - j] / place) % 10] - 1] = arr[n - 1 - j];
		count[(arr[n - 1 - j] / place) % 10]--;
	}

	/* Copy the sorted elements back to the original array */
	for (j = 0; j < n; j++)
		arr[j] = output[j];

	/* Free the memory allocated for the output array */
	free(output);

	/* Print the current state of the array after sorting at this place */
	print_array(arr, n);
}

/**
 * radix_sort - Sort array int in ascending order.
 * @array: sort int array
 * @size: byte size
 * Return: void
 */
void radix_sort(int *array, size_t size)
{
	int max, place;

	/* Check if the array has more than one element */
	if (size > 1)
	{
		/* Find the maximum element in the array */
		max = getMax(array, size);

		/* Perform counting sort for each place (1s, 10s, 100s, etc.) */
		for (place = 1; (max / place) > 0; place *= 10)
		{
			countingSort(array, size, place);
		}
	}
}
