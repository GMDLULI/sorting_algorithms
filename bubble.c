#include "sort.h"

/**
 * swap - swaps integers
 * @x: first integer
 * @y: second integer
 */

void swap(int *x, int *y)
{
	int temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

/**
 * bubble_sort - Bubble sort algorithm for sorting items
 *
 * @array: pointer to the array that is to be sorted
 * @size: size of the array
 *
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j, len = size;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < len - 1; i++)
	{
		for (j = 0; j < (len - 1 - i); j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(array + i, array + i - 1);
				print_array(array, size);
			}
		}
	}
}