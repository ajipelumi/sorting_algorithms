#include "sort.h"

int get_max(int *array, size_t size);

/**
 * counting_sort - sorts an array of integers in ascending
 * order using the Counting sort algorithm
 *
 * @array: array of integers
 * @size: size of arrray
 *
 * Return: void
 */

void counting_sort(int *array, size_t size)
{
	int i, max;
	int *count = NULL, *position = NULL;

	if (size < 2 || array == NULL) /* array does not need to sort */
	{
		return;
	}

	for (i = 1; i < (int)size; i++) /* check for identical elements */
	{
		/* check every element with first element */
		if (array[i] != array[0])
		{
			break;
		}
		if (i == (int)(size - 1)) /* last item met */
		{
			return; /* unneccessary to sort identical elements */
		}
	}
	max = get_max(array, size);
	count = malloc(sizeof(int) * (max + 1));
	if (count == NULL) /* malloc fails */
		return;
	for (i = 0; i <= max; i++)
		count[i] = 0; /* initialize everything with 0 */
	for (i = 0; i < (int)size; i++)
		count[array[i]] = 1; /* initialize array items with 1 */

	printf("%d, ", count[0]); /* print first item */
	for (i = 1; i <= max; i++)
	{
		count[i] += count[i - 1]; /* increment count */
		printf("%d", count[i]);
		if (i <= (max - 1))
		{
			printf(", ");
		}
	}
	printf("\n");

	position = malloc(sizeof(int) * size);
	if (position == NULL) /* malloc fails */
		return;
	for (i = size - 1; i >= 0; i--) /* store array items in correct position */
		position[--count[array[i]]] = array[i];
	for (i = 0; i < (int)size; i++)
		array[i] = position[i]; /* array now copies position */
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
