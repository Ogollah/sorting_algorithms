#include "sort.h"

/**
 * swap - Swaps two integers.
 * @x: Pointer to the first integer.
 * @y: Pointer to the second integer.
 */
void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

/**
 * bubble_sort - Sorts an array of integers in
 *                ascending order using Bubble sort.
 * @array: Pointer to the array.
 * @size: Size of the array.
 */
void bubble_sort(int *array, size_t size)
{
	int swapped;

	for (size_t i = 0; i < size - 1; i++)
	{
		swapped = 0;
		for (size_t j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				swapped = 1;
			}
		}

		if (!swapped)
		{
			break;
		}

		for (size_t k = 0; k < size; k++)
		{
			printf("%d ", array[k]);
		}
		printf("\n");
	}
}
