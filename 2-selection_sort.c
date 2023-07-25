#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order
 *                  using Selection sort.
 * @array: Pointer to the array.
 * @size: Size of the array.
 */
void selection_sort(int *array, size_t size)
{
	for (size_t i = 0; i < size - 1; i++)
	{
		size_t min_index = i;

		for (size_t j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_index])
			{
				min_index = j;
			}
		}
		if (min_index != i)
		{
			swap(&array[i], &array[min_index]);
			for (size_t k = 0; k < size; k++)
			{
				printf("%d ", array[k]);
			}
			printf("\n");
		}
	}
}
