#include "sort.h"

void sort_array_size_2(int *array);
void count_sort(int *array, size_t size, int pos);
int get_max(int *array, size_t size);

/**
 * radix_sort - sorts an array of integers in ascending
 * order using the Radix sort algorithm
 *
 * @array: array of integers
 * @size: size of arrray
 *
 * Return: void
 */

void radix_sort(int *array, size_t size)
{
	int pos, max;

	if (size < 2 || array == NULL) /* array does not need to sort */
	{
		return;
	}

	if (size == 2) /* array of size 2 */
	{
		sort_array_size_2(array); /* call sort */
		print_array(array, size); /* print array */
		return;
	}

	/* get max integer */
	max = get_max(array, size);

	/* pos tracks ones/tenths/hundredths of the max integer */
	/* increases by (pos * 10) for every iteration */
	for (pos = 1; (max / pos) > 0; pos = pos * 10)
	{
		/* count sort each digit place (ones/tenths/hundredths)*/
		count_sort(array, size, pos);

		/* print array for every digit place */
		print_array(array, size);
	}
}

/**
 * sort_array_size_2 - sorts an array of size 2
 *
 * @array: array of integers
 *
 * Return: void
 */

void sort_array_size_2(int *array)
{
	int temp;

	/* swap if first item is greater than second item */
	if (array[0] > array[1])
	{
		temp = array[0];
		array[0] = array[1];
		array[1] = temp;
	}
	else /* no swap needed */
	{
		return;
	}
}

/**
 * count_sort - sorts an array of integers using the Count sort algorithm
 *
 * @array: array of integers
 * @size: size of arrray
 * @pos: index position
 *
 * Return: void
 */

void count_sort(int *array, size_t size, int pos)
{
	int i;
	int *count, *position;

	count = malloc(sizeof(int) * (size + 1));
	if (count == NULL) /* malloc fails */
	{
		return;
	}

	position = malloc(sizeof(int) * size);
	if (position == NULL) /* malloc fails */
	{
		return;
	}

	for (i = 0; i <= (int)size; i++)
	{
		count[i] = 0; /* initialize everything with 0 */
	}

	for (i = 0; i < (int)size; i++) /* iterate through array size */
	{
		/* increment every occurence of digit by 1 */
		count[((array[i] / pos) % 10)]++;
	}

	for (i = 1; i < (int)size; i++)
	{
		/* increment count */
		count[i] = count[i] + count[i - 1];
	}

	for (i = (int)(size - 1); i >= 0; i--)
	{
		/* store array items in correct position */
		position[--count[(array[i] / pos) % 10]] = array[i];
	}

	for (i = 0; i < (int)size; i++)
	{
		array[i] = position[i]; /* array now copies position */
	}
	free(count); /* free count */
	free(position); /* free position */
}

/**
 * get_max - get highest integer in the array
 *
 * @array: array of integers
 * @size: size of arrray
 *
 * Return: max integer
 */

int get_max(int *array, size_t size)
{
	int i, temp;

	temp = array[0]; /* hold first integer */
	for (i = 1; i < (int)size; i++) /* iterate through array */
	{
		if (array[i] > temp) /* if item at index is greater */
		{
			temp = array[i]; /* temp now holds max integer */
		}
	}
	return (temp); /* return max integer */
}
