#include "sort.h"

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

	/* get max integer */
	max = get_max(array, size);

	/* pos tracks ones/tenths/hundredths of the max integer */
	/* increases by (pos * 10) for every iteration */
	for (pos = 1; max / pos > 0; pos = pos * 10)
	{
		/* count sort each digit place (ones/tenths/hundredths)*/
		count_sort(array, size, pos);

		/* print array for every digit place */
		print_array(array, size);
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
	int count[10] = {0}; /* initialize count to 0 */
	int b[10]; /* ones/tenths/hundreths can only be single digit so 0 - 9 */

	for (i = 0; i < (int)size; i++) /* iterate through array size */
	{
		/* increment every occurence of digit by 1 */
		count[(array[i] / pos) % 10]++;
	}

	for (i = 1; i < (int)size; i++)
	{
		/* increment count */
		count[i] = count[i] + count[i - 1];
	}

	for (i = size - 1; i >= 0; i--)
	{
		/* store array items in correct position */
		b[--count[(array[i] / pos) % 10]] = array[i];
	}

	for (i = 0; i < (int)size; i++)
	{
		array[i] = b[i]; /* array now copies b */
	}
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
