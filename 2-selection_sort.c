#include"sort.h"

/**
 * swap - swaps intergers
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
 * selection_sort - sorts the array in accending order
 * @array: array to be sorted
 * @size: size of array
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j;
	size_t min_value;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min_value = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_value])
				min_value = j;
		}
		if (min_value != i)
		{
			swap(&array[i], &array[min_value]);
			print_array(array, size);
		}
	}
}
