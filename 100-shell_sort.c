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
 * shell_sort - Sorts an array of integers using the Shell sort
 * algorithm with the Knuth sequence.
 * @array: Array to be sorted.
 * @size: Size of the array.
 */
void shell_sort(int *array, size_t size)
{
	int ks = 1;
	size_t i;

	while ((size_t)ks < size / 3)
	{
		ks = ks * 3 + 1;
	}

	while (ks >= 1)
	{
		for (i = ks; i < size; i++)
		{
			int key = array[i];
			int j = i;

			while (j >= ks && array[j - ks] > key)
			{
				array[j] = array[j - ks];
				j -= ks;
			}

			array[j] = key;
		}

		print_array(array, size);
		ks = (ks - 1) / 3;
	}
}

