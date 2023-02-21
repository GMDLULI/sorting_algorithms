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
	bool swapped = false;
	
	if (array == NULL || size < 2)
		return;

	while (swapped == false)
	{
		swapped = true;
		for (i = 0; i < (size - 1); i++)
		{
			for (j = 0; j < (size - 1 - i); j++)
			{
				if (array[j] > array[j + 1])
				{
					temp = array[j + 1];
					array[j + 1] = array[j];
					array[j] = temp;
					print_array(array, size);
					swapped = false;
				}
			}
			size--;
		}
	}
}
