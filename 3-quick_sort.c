#include "sort.h"

/**
 * swap - Swaps two integers.
 * @num: first integer.
 * @num2: second integer.
 */
void swap(int *num, int *num2)
{
	int temp = *num;

	*num = *num2;
	*num2 = temp;
}

/**
 * partition - Partitions the array around the pivot element for QuickSort.
 * @array: array to be sorted.
 * @low: starting index of the partition.
 * @high: ending index of the partition.
 * @size: size of the array.
 *
 * Return: The index of the pivot element after partitioning.
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int j, i = low - 1;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (array[i] != array[j])
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}

	if (array[i + 1] != array[high])
	{
		swap(&array[i + 1], &array[high]);
		print_array(array, size);
	}

	return (i + 1);
}

/**
 * quick_sorter - recursive function to perform QuickSort.
 * @array: array to be sorted.
 * @low: starting index of the array.
 * @high: ending index of the array.
 * @size: size of the array.
 */
void quick_sorter(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pivot_index = partition(array, low, high, size);

		quick_sorter(array, low, pivot_index - 1, size);
		quick_sorter(array, pivot_index + 1, high, size);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order using QuickSort.
 * @array: array to be sorted.
 * @size: size of the array.
 */
void quick_sort(int *array, size_t size)
{
	quick_sorter(array, 0, size - 1, size);
}

