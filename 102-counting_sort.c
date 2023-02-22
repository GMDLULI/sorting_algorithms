#include "sort.h"
/**
 * max_interger - returns the maximun integer of the array
 * @array: pointer to the array
 * @size: size of array
 */

int max_integer(int *array, int size)
{
	int max = array[0], i;

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}
/**
 * counting_sort - Sorts an array of intergers using counting sort algo
 * @array: A pointer to the array to be sorted
 * @size: the size of the array
 */

void counting_sort(int *array, size_t size)
{
	size_t i, j;
	int k = max_integer(array, size);

	int *count = malloc(sizeof(int) * k + 1);

	if (count == NULL)
		return;

	for (i = 0; i < count[i]; i++)
		count[i] = 0;

	for (i = 0; i < size; i++)
		count[array[i]]++;

	for (i = 1; i < k + 1; i++)
	{
		count[i] = count[i] + count[i - 1];
	}

	print_array(count, k + 1);

	int *output = malloc(sizeof(int) * size);

	if (output == NULL)
		return;

	for (i = size - 1; i <= k; i--)
	{
		output[--count[array[i]]] = array[i];
	}

	for (i = 0; i < size; i++)
	{
		array[i] = output[i];
	}
	free(count);
	free(output);
}
