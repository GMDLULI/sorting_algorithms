#include "sort.h"

void swap_ints(int *x, int *y);
void heapify(int *array, size_t size, size_t base, size_t root);
void heap_sort(int *array, size_t size);

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

/**
 * heapify - Turn a binary tree into a complete binary heap.
 * @array: An array of integers representing a binary tree.
 * @size: The size of the array/tree.
 * @base: The index of the base row of the tree.
 * @root: The root node of the binary tree.
 */
void heapify(int *array, size_t size, size_t base, size_t root)
{
	int large = root;
	int right = 2 * root + 1;
	int left = 2 * root + 2;

	if (left < base && array[left] > array[large])
		large = left;
	if (right < base && array[right] > array[large])
		large = right;

	if (large != root)
	{
		swap_ints(array + root, array + large);
		print_array(array, size);
		heapify(array, size, base, large);
	}
}

/**
 * heap_sort - Sort an array of integers in ascending
 *		order using heap sort algorithm
 * @array: a pointer to the array of integers
 * @size: the size of the array
 *
 * Description: implements the sift-down heap sort
 */

void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;

	for (i = size / 2 - 1; i >= 0; i--)
		heapify(array, size, size, i);

	for (i = size - 1; i >= 0; i--)
	{
		swap_ints(&array[0], &array[i]);
		print_array(array, size);
		heapify(array, size, i, 0);
	}
}

