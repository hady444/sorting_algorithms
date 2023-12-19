#include "sort.h"
void quick_sort_Lomuto(int *array, size_t start, size_t end, size_t size);
void swap(int *array, int i, int j);
/**
 * quick_sort - sorts an array using the Quick sort algorithm
 * @array: array of ints given
 * @size: size of array.
 */
void quick_sort(int *array, size_t size)
{
	if (!array)
		return;
	quick_sort_Lomuto(array, 0, size - 1, size);
}
/**
 * swap - swap values
 * @array: provided array
 * @i: index 1
 * @j: index 2
 */
void swap(int *array, int i, int j)
{
	int tmp;

	tmp = array[i];
	array[i] = array[j];
	array[j] = tmp;
}
/**
 * quick_sort_Lomuto - recursive function sorts an array using the Quick sort.
 * @array: array of ints given
 * @start: index of subarray
 * @end: end index of sub array
 * @size: size of array.
 */
void quick_sort_Lomuto(int *array, size_t start, size_t end, size_t size)
{
	size_t j, i;
	int pivot;

	if (start >= end || array == NULL)
		return;

	pivot = array[end];
	j = start;
	for (i = start; i < end; i++)
	{
		if (array[i] <= pivot)
		{
			if (j != i)
			{
				swap(array, j, i);
				print_array(array, size);
			}
			j++;
		}
	}
	if (j != end)
	{
		swap(array, j, end);
		print_array(array, size);
	}
	if (j - start > 1)
		quick_sort_Lomuto(array, start, j - 1, size);
	if (end - j > 1)
		quick_sort_Lomuto(array, j + 1, end, size);
}
