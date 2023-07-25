#include "sort.h"

/**
 * lomuto_partition - Performs the Lomuto partition scheme for Quick sort.
 * @array: Pointer to the array.
 * @low: Starting index of the partition to be sorted.
 * @high: Ending index of the partition to be sorted.
 * @size: Size of the array.
 * Return: The index of the pivot after partitioning.
 */
size_t lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;

	for (int j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swap(&array[i], &array[j]);
			for (size_t k = 0; k < size; k++)
			{
				printf("%d ", array[k]);
			}
			printf("\n");
		}
	}
	swap(&array[i + 1], &array[high]);
	for (size_t k = 0; k < size; k++)
	{
		printf("%d ", array[k]);
	}
	printf("\n");
	return (i + 1);
}

/**
 * quick_sort_helper - Recursive helper function for Quick sort.
 * @array: Pointer to the array.
 * @low: Starting index of the partition to be sorted.
 * @high: Ending index of the partition to be sorted.
 * @size: Size of the array.
 */
void quick_sort_helper(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		size_t partition_index = lomuto_partition(array,
							  low, high, size);
		if (partition_index != 0)
			quick_sort_helper(array, low, partition_index - 1,
					  size);
		quick_sort_helper(array, partition_index + 1, high, size);
	}
}

/**
 * quick_sort - Sorts an array of integers in
 *        ascending order using Quick sort (Lomuto partition).
 * @array: Pointer to the array.
 * @size: Size of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_helper(array, 0, size - 1, size);
}
