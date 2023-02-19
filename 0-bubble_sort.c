#include "sort.h"

/**
 * bubble_sort - Bubble sort algorithm for sorting items
 *
 * @array: pointer to the array that is to be sorted
 * @size: size of the array
 *
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j, temp;

	if (size >= 2)
	{
		for (i = 0; i < size; i++)
		{
			for (j = 0; j < size - 1; j++)
			{
				temp = 0;
				if (array[j] > array[j + 1])
				{
					temp = array[j + 1];
					array[j + 1] = array[j];
					array[j] = temp;
					print_array(array, size);
				}
			}
		}
	}
}
