#include "sort.h"

void swap(int *a, int *b);

/**
 * shell_sort - sorts an array of integers in ascending
 * order using the Shell sort algorithm
 *
 * @array: array of integers
 * @size: size of arrray
 *
 * Return: void
 */

void shell_sort(int *array, size_t size)
{
	int i, j, gap;

	if (size < 2 || array == NULL) /* array does not need to sort */
	{
		return;
	}

	gap = 1;
	while ((gap * 3 + 1) < (int)size)
	{
		gap = gap * 3 + 1; /* get gap */
	}

	for (; gap > 0; gap = gap / 3) /* iterate through gap sequence */
	{
		for (j = gap; j < (int)size; j++) /* j starts from gap untill size */
		{
			for (i = j - gap; i >= 0; i = i - gap) /* i will decrement from gap */
			{
				/* if index item is greater than item at gap */
				if (array[i] > array[i + gap])
				{
					/* call swap */
					swap(&array[i], &array[i + gap]);
				}
			}
		}
		print_array(array, size); /* print array */
	}
}

/**
 * swap - swaps integers
 *
 * @a: first integer
 * @b: second integer
 *
 * Return: void
 */

void swap(int *a, int *b)
{
	int temp;

	/* swap items */
	temp = *a;
	*a = *b;
	*b = temp;
}
