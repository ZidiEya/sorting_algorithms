#include "sort.h"
/**
 * swaps - swap and prints ints 
 * @array: the array for printing function
 * @size: the size of array for printing function
 * @a: one int
 * @b: the other int
 */
void swaps(int *array, size_t size, int *a, int *b)
{
	if (*a != *b)
	{
		*a = *a + *b;
		*b = *a - *b;
		*a = *a - *b;
		print_array((const int *)array, size);
	}
}
/**
 * kwiksort - quick sort by lamuto partition
 * @array: the array
 * @size: size of array
 * @low: low [] of sort
 * @high: high [] of sort
 *
 */
void kwiksort(int *array, size_t size, ssize_t low, ssize_t high)
{
	if (low < high)
	{
		size_t part = partition(array, size, low, high);

		kwiksort(array, size, low, part - 1);
		kwiksort(array, size, part + 1, high);
	}
}

/**
 * quick_sort - for quick sort
 * embetter
 * @array: the array to sort
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || !size)
		return;
	kwiksort(array, size, 0, size - 1);
}
/**
 * partition -array
 * @array: the array
 * @size: the size of array
 * @low: the bottom of the index
 * @high: the top 
 * Return: size_t part and the partition value
 */
size_t partition(int *array, size_t size, ssize_t low, ssize_t high)
{
	int i, j, pivot;

	pivot = array[high];

	for (j = low, i = j; j < high; j++)
	{
		if (array[j] < pivot)
		{
			swaps(array, size, &array[j], &array[i++]);
		}
	}
	swaps(array, size, &array[i], &array[high]);
	return (i);
}
