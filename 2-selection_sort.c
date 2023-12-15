#include "sort.h"
/**
 * selection_sort - sorts an array using the Selection sort algorithm
 * @array: array of ints to be sorted
 * @size: size of array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_index;
	int tmp, flag = 0;

	if (!array)
		return;
	for (i = 0; i < (size - 1); i++)
	{
		tmp = array[i];
		for (j = i + 1; j < size; j++)
		{
			if (tmp > array[j])
			{
				tmp = array[j];
				min_index = j;
				flag = 1;
			}
		}
		if (flag == 1)
		{
			tmp = array[i];
			array[i] = array[min_index];
			array[min_index] = tmp;
			print_array(array, size);
		}
	}
}
