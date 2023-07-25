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
 * bubble_sort - Sorts an array of integers in using Bubble Sort.
 * @array: array to be sorted.
 * @size: size of the array.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				print_array(array, size);
			}
		}
	}
}

