#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending
 * order using the Selection sort algorithm
 *
 * @array: array of integers
 * @size: size of arrray
 *
 * Return: void
 */

void selection_sort(int *array, size_t size)
{
	int temp;
	size_t i, j, idx;

	if (size < 2 || array == NULL) /* array does not need to sort */
	{
		return;
	}

	/* iterate through array */
	for (i = 0; i < (size - 1); i++)
	{
		/* store current index in temp */
		temp = array[i];
		idx = i;

		/* iterate through array again */
		for (j = i + 1; j < size; j++)
		{
			/* check for smallest number */
			if (temp > array[j])
			{
				/* temp now holds smallest number */
				temp = array[j];
				/* index position that needs to be swapped */
				idx = j;
			}
		}
		/* if index changes, item swapped */
		if (idx != i)
		{
			/* item at index is swapped with temp */
			array[idx] = array[i];
			array[i] = temp;
			print_array(array, size); /* print array */
		}
	}
}
