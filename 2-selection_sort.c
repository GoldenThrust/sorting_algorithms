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
 * selection_sort - Sorts an array of integers using Selection Sort.
 * @array: array to be sorted.
 * @size: size of the array.
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min;

	for (i = 0; i < size; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[min] > array[j])
			{
				min = j;
			}
		}
		if (min != i)
		{
			swap(&array[i], &array[min]);
			print_array(array, size);
		}
	}
}

