#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
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

	for (h = 1; h < (size / 3);)
	{
		h = h * 3 + 1;
	}
	for (; h >= 1; h /= 3)
	{
		for (i = h; i < size; i++)
		{

			j = i;
			while (j >= h && array[j - h] > array[j])
			{
				swap_ints(array + j, array + (j - h));
				j -= h;
			}
		}
		print_array(array, size);
	}
}
