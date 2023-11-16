#include "sort.h"

/**
 * bubble_sort - bubble sorting alogarithim
 * @array: the array
 * @size: amount of array bytes used
 * Return: nothing
 */
void bubble_sort(int *array, size_t size)
{
	int swapped = 1;
	size_t i, tmp, s = size;

	while (swapped)
	{
		swapped = 0;
		for (i = 1; i < s; i++)
		{
			if (array[i - 1] > array[i])
			{
				tmp = array[i - 1];
				array[i - 1] = array[i];
				array[i] = tmp;

				swapped = 1;
				print_array(array, size);
			}
		}
		s--;
	}
}
