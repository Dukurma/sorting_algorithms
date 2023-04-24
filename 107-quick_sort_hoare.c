#include "sort.h"

/**
 * swap_values - swaps 2 values in an array of ints
 *
 * @array: the array of ints
 * @i1: index of first value
 * @i2: index of 2nd value
 *
 * Return: the array with value
 */

void swap_values(int **array, ssize_t i1, ssize_t i2)
{
	int tmp;

	tmp = (*array)[i1];
	(*array)[i1] = (*array)[i2];
	(*array)[i2] = tmp;
}

/**
 * partition - partitions for quicksort using the Hoare scheme
 *
 * @array: the array to sort
 * @low: the lowest index of the partition to sort
 * @high: the highest index of the partition to sort
 * @size: size of the array
 *
 * Return: index of the partition
 */
size_t partition(int *array, ssize_t low, ssize_t high, size_t size)
{
	int pivot;

	pivot = array[high];

	while (low <= high)
	{
		while (array[low] < pivot)
			low++;
		while (array[high] > pivot)
			high--;
		if (low <= high)
		{
			if (low != high)
			{
				swap_values(&array, low, high);
				print_array(array, size);
			}
			low++;
			high--;
		}
	}
	return (hi);
}

/**
 * _quick_sort - partitions the array, then sorts each partition
 *
 * @array: the array to sort
 * @low: the lowest index of the partition to sort
 * @high: the highest index of the partition to sort
 * @size: size of the array
 */

void _quick_sort(int *array, ssize_t low, ssize_t high, size_t size)
{
	ssize_t pivot;

	if (low < high)
	{
		pivot = partition(array, low, high, size);
		_quick_sort(array, low, pivot, size);
		_quick_sort(array, pivot + 1, high, size);
	}
}



/**
 * quick_sort_hoare - sorts an array of integers using quicksort
 *
 * @array: the array of integers
 * @size: the size of the array
 */

void quick_sort_hoare(int *array, size_t size)
{
	ssize_t low = 0;
	ssize_t high = (size - 1);

	if (!array || size < 2)
		return;

	_quick_sort(array, low, high, size);
}
