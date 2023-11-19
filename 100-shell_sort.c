#include "sort.h"

/**
 * shell_sort - sorting the elements at a specific interval
 * rather than comparing adjacent elements
 * @array: list of values
 * @size: array size
 * Return: nothing
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1, i, j;
	int tmp;

	if (size < 2)
		return;

	while (gap < size / 3)
		gap = gap * 3 + 1;

	while (gap > 0)
	{

		for (i = gap; i < size; i++)
		{
			tmp = array[i];
			j = i;

			while (j > gap - 1 && array[j - gap] >= tmp)
			{
				array[j] = array[j - gap];
				j = j - gap;
			}
			array[j] = tmp;

		}
		gap = (gap - 1) / 3;
		print_array(array, size);
	}
}
