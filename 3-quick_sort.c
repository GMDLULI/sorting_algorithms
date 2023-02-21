#include"sort.h"
int lomuto_partition(int *array, int high, int low, size_t size);
void lomuto_sort(int *array, int low, int high, size_t size);
void quick_sort(int *array, size_t size);

/**
 * lomuto_partition - order a subset of an array of integers according to
 *			the lomuto partition scheme (pivot as last element)
 * @array: the array of integers to sort
 * @size: size of array
 * @high: the starting index of the subset to order
 * @low: the ending index of the subset to order
 * Return: no return
 */

int lomuto_partition(int *array, int high, int low, size_t size)
{
	int pivot = array[high];
	int i = (low - 1);
	int temp;

	for (int j = low; j <= (high - 1); j++)
	{
		if (array[j] < pivot)
		{
			temp = array[j];
			array[j] = array[i];
			array[i] = temp;
			print_array(array, size);
			i++;
		}
	}
	if (array[high] > pivot)
	{
		temp = array[i + 1];
		array[i + 1] = array[high];
		array[high] = temp;
		print_array(array, size);
	}
	return (i + 1);
}
/**
 * lomuto_sort - recursivly implement the quicksort algorithm
 * @array: the array to be sorted
 * @size: the size of the array
 * @high: the starting index of the array partition to order
 * @low: the ending index of the array partition to order
 */

void lomuto_sort(int *array, int low, int high, size_t size)
{
	int pi;


	if (low < high)
	{
		pi = lomuto_partition(array, low, high, size);
		lomuto_sort(array, low, (pi - 1), size);
		lomuto_sort(array, (pi + 1), high, size);
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
