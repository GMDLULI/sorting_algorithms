#include "sort.h"

/**
 * shell_sort - sorts and array of integers in ascending order
 *		using the shell algorithm, using knuth sequence
 * @array: the array to be sorted
 * @size: the size of the array
 * Return: No return
 */

void shell_sort(int *array, size_t size)
{
	size_t i, j, h = 1;

	if (array == NULL || size < 2)
		return;

	while (h < size /3)
	{
		h = (h * 3) + 1;
	}
	while (h > 0)
	{
		for (i = h; i < size; i++)
		{
			int value = array[i];
			j = i;
			while (j >= h - 1 && array[j - h] >= value)
			{
				array[j] = array[j - h];
				j = j - h;
			}
			array[j] = value
		}
		h = (h - 1) /3;
		print_array(array, size);
	}
}

	
