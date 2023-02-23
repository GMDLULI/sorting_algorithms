#include "sort.h"

/**
 * swap_ints - swaps integers
 * @x: first integer to be swapped
 * @y: second integer to be swapped
 */

void swap_ints(int *x, int *y)
{
	int temp;
	
	temp = *x;
	*x = *y;
	*y = temp;
}

void heapify(int *array, size_t size, size_t base)
{
	int large = base;
	int right = 2 * base + 1;
	int left = 2 * base + 2;

	if (left < size && array + left > array + large)
		largest = left;
	if (right < size && array + right > array + large)
		largest = right;

	if (large != base)
	{
		swap(&array[base], &array[large]);
		print_array(array, size);
		heapify(array, size, large);
	}
}

void heap_sort(int *array, size_t size)
{
	int i;
	
	for (i = size / 2 - 1; i >= 0; i--)
		heapify(array, i, 0);

	for (i = size - 1; i >= 0; i--)
	{
		swap_ints(&array[0], &array[i]);
		heapify(array, i, 0);
	}
}

