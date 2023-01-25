#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending
 * order using the Bubble sort algorithm
 *
 * @array: array of integers
 * @size: size of arrray
 *
 * Return: void
 */

void bubble_sort(int *array, size_t size)
{
	int temp, flag;
	size_t i, j;

	for (i = 0; i < (size - 1); i++) /* iterate size times */
	{
		flag = 0; /* flag to track if swap occurs */
		for (j = 0; j < (size - 1); j++) /* iterate size times again */
		{
			if (array[j] > array[j + 1]) /* if current number is greater than next */
			{
				temp = array[j]; /* temp holds first integer */
				array[j] = array[j + 1]; /* swap occurs */
				array[j + 1] = temp;
				flag = 1; /* flag is updated to indicate swap */
				print_array(array, size); /* print every time swap occurs */
			}
		}
	}
}
