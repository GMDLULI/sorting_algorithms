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
	size_t i, j, h;

	if (array == NULL || size < 2)
		return;

	for ( h = 1; h < (size /3);)
	{
		h = (h * 3) + 1;
	}
	for (; h >= 1; h /= 3)
	{
		for (i = h; i < size; i++)
		{
			int value = array[i];
			j = i;
			while (j >= h && array[j - h] > value)
			{
				array[j] = array[j - h];
				j -= h;
			}
			array[j] = value;
		}
		print_array(array, size);
	}
}

	
