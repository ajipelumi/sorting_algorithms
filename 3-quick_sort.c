#include "sort.h"

void sort(int *array, int start, int end, size_t size);
int partition(int *array, int low, int high, size_t size);
void swap(int *a, int *b);

/**
 * quick_sort - sorts an array of integers in ascending
 * order using the Quick sort algorithm
 *
 * @array: array of integers
 * @size: size of arrray
 *
 * Return: void
 */

void quick_sort(int *array, size_t size)
{
	int start, end;

	if (size < 2 || array == NULL) /* array does not need to sort */
	{
		return;
	}

	start = 0; /* initiate start */
	end = (size - 1); /* initiate end */
	sort(array, start, end, size); /* call sort function */
}

/**
 * sort - recursively sorts an array of integers
 *
 * @array: array of integers
 * @start: start index
 * @end: end index
 * @size: size of array
 *
 * Return: void
 */

void sort(int *array, int start, int end, size_t size)
{
	int p_index;

	if (start >= end) /* base case */
	{
		return;
	}

	p_index = partition(array, start, end, size); /* call partition */
	sort(array, start, p_index - 1, size); /* recursive function to sort */
	sort(array, p_index + 1, end, size); /* recursive function to sort */
}

/**
 * partition - partitions an array of integers using pivot element
 *
 * @array: array of integers
 * @low: lowest index
 * @high: highest index
 * @size: size of array
 *
 * Return: partitioned index
 */

int partition(int *array, int low, int high, size_t size)
{
	int i, pivot, idx;

	pivot = array[high]; /* store last number as pivot */
	idx = low; /* idx to track items */

	for (i = low; i < high; i++)
	{
		if (array[i] < pivot) /* int is less than pivot */
		{
			swap(&array[i], &array[idx]); /* swap items */
			if (i != idx) /* if swap occurs, i will not be equal to idx */
			{
				print_array(array, size); /* print because swap occurs */
			}
			idx += 1; /* increase index by 1 */
		}
	}

	swap(&array[idx], &array[high]); /* swap pivot with index */
	if (high != idx) /* if pivot item is swapped, high != idx */
	{
		print_array(array, size); /* print because swap occurs */
	}
	return (idx);
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
