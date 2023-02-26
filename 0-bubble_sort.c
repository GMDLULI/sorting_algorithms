#include "sort.h"

/**
<<<<<<< HEAD
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
 * bubble_sort - Sort an array of integers in ascending order.
 * @array: An array of integers to sort.
 * @size: The size of the array.
=======
 * bubble_sort - Bubble sort algorithm for sorting items
 *
 * @array: pointer to the array that is to be sorted
 * @size: size of the array
>>>>>>> 8c66a1a1b7916dd01f244466ed20962321ad9c8e
 *
 * Description: Prints the array after each swap.
 */
void bubble_sort(int *array, size_t size)
{
<<<<<<< HEAD
	size_t i, len = size;
	bool bubbly = false;

	if (array == NULL || size < 2)
		return;

	while (bubbly == false)
	{
		bubbly = true;
		for (i = 0; i < len - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap_ints(array + i, array + i + 1);
				print_array(array, size);
				bubbly = false;
=======
	size_t i, j, temp;

	if (size >= 2)
	{
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
				}
>>>>>>> 8c66a1a1b7916dd01f244466ed20962321ad9c8e
			}
		}
		len--;
	}
}
