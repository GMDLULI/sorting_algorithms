#include "sort.h"

void swap_ints(int *a, int *b);
int lomuto_partition(int *array, int high, int low, size_t size);
void lomuto_sort(int *array, int low, int high, size_t size);
void quick_sort(int *array, size_t size);
/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int tmp;
	if (*a != *b)
	{
		tmp = *a;
		*a = *b;
		*b = tmp;
	}
}
/**
 * lomuto_partition - order a subset of an array of integers according to
 *			the lomuto partition scheme (pivot as last element)
 * @array: the array of integers to sort
 * @size: size of array
 * @left: the starting index of the subset to order
 * @right: the ending index of the subset to order
 * Return: no return
 */

int lomuto_partition(int *array, int right, int left, size_t size)
{
	int *pivot = array + right;
	int i = left;
	int temp;

	for (int j = left; j < right; j++)
	{
		if (array[j] < *pivot)
		{
			if (i < j)
			{
				swap_ints(&array[j], &array[i]);
				print_array(array, size);
				i++;
			}
		}
	}
	if (array[i] > *pivot)
	{
		swap_ints(&array[i], &pivot);
		print_array(array, size);
	}
	return (i);
}

/**
 * lomuto_sort - recursivly implement the quicksort algorithm
 * @array: the array to be sorted
 * @size: the size of the array
 * @left: the starting index of the array partition to order
 * @right: the ending index of the array partition to order
 */

void lomuto_sort(int *array, int left, int right, size_t size)
{
	int pi;


	if (right - left > 0)
	{
		pi = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, pi - 1);
		lomuto_sort(array, size, pi + 1, right);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order
 *		using quick sort algorithm
 * @array: An array of intgers
 * @size: The size of the array
 */

void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
