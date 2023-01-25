#include "sort.h"

void divide(int *array, int size);
void merge(int *array, int *left, int *right, int size);
void merge_print(int *left, int *right, int n1, int n2);
void merge_items(int *a, int *l, int *r, int n1, int n2, int i, int j, int k);

/**
 * merge_sort - sorts an array of integers in ascending
 * order using the Merge sort algorithm
 *
 * @array: array of integers
 * @size: size of arrray
 *
 * Return: void
 */

void merge_sort(int *array, size_t size)
{
	int s = size; /* cast size as int */

	if (size < 2 || array == NULL) /* array does not need to sort */
	{
		return;
	}

	divide(array, s); /* divide call */
}

/**
 * divide - recursion to divide array into half
 *
 * @array: array of integers
 * @size: size of arrray
 *
 * Return: void
 */

void divide(int *array, int size)
{
	int mid = size / 2, i, j;
	int *both;

	if (size > 1) /* base case */
	{
		both = malloc(sizeof(int) * size);
		if (both == NULL) /* malloc fails */
		{
			return;
		}

		for (i = 0; i < mid; i++) /* iterate until middle */
		{
			both[i] = array[i]; /* copy left of array to allocated memory */
		}
		for (j = mid; j < size; j++) /* iterate until size */
		{
			both[j] = array[j]; /* copy right of array to allocated memory */
		}
		divide(both, mid); /* divide left side */
		divide(both + mid, size - mid); /* divide right side */
		merge(array, both, both + mid, size); /* merge both sides */
		free(both); /* free both */
	}
}

/**
 * merge - merge left and right part of the array
 *
 * @array: array of integers
 * @left: left side of the array
 * @right: right side of the array
 * @size: size of arrray
 *
 * Return: void
 */

void merge(int *array, int *left, int *right, int size)
{
	int n1 = size / 2;
	int n2 = size - n1;
	int i, j, k, p;

	merge_print(left, right, n1, n2); /* call print function */

	i = 0, j = 0, k = 0;
	while (i < n1 && j < n2) /* while looping through left and right items */
	{
		if (left[i] <= right[j]) /* if left item is greater */
		{
			array[k] = left[i]; /* copy to array */
			k++; /* increment array index */
			i++; /* increment left array index */
		}
		else /* if right item is greater */
		{
			array[k] = right[j]; /* copy to array */
			k++; /* increment array index */
			j++; /* increment right array index */
		}
	}

	/* merge remaining items in both left and right arrays */
	merge_items(array, left, right, n1, n2, i, j, k);

	printf("[Done]: ");
	for (p = 0; p < size; p++) /* loop through array to print array */
	{
		printf("%d", array[p]);
		if (p < (size - 1)) /* last item in the array not met */
		{
			printf(", ");
		}
	}
	printf("\n");
}

/**
 * merge_print - print left and right array as merging takes place
 *
 * @left: left side of the array
 * @right: right side of the array
 * @n1: size of left side
 * @n2: size of right side
 *
 * Return: void
 */

void merge_print(int *left, int *right, int n1, int n2)
{
	int i, j;

	printf("Merging...\n");
	printf("[left]: ");
	for (i = 0; i < n1; i++) /* loop through left array and print items */
	{
		printf("%d", left[i]);
		if (i < (n1 - 1)) /* last item in the array not met */
		{
			printf(", ");
		}
	}

	printf("\n");
	printf("[right]: ");
	for (j = 0; j < n2; j++) /* loop through right array and print items */
	{
		printf("%d", right[j]);
		if (j < (n2 - 1)) /* last item in the array not met */
		{
			printf(", ");
		}
	}
	printf("\n");
}

/**
 * merge_items - merges items left in both arrays
 *
 * @a: array of integers
 * @l: left side of the array
 * @r: right side of the array
 * @n1: size of left side
 * @n2: size of right side
 * @i: left index
 * @j: right index
 * @k: array index
 *
 * Return: void
 */

void merge_items(int *a, int *l, int *r, int n1, int n2, int i, int j, int k)
{
	while (i < n1) /* loop through left array for items yet to be copied */
	{
		a[k] = l[i]; /* copy to array */
		k++; /* increment array index */
		i++; /* increment left array index */
	}

	while (j < n2) /* loop through right array for items yet to be copied */
	{
		a[k] = r[j]; /* copy to array */
		k++; /* increment array index */
		j++; /* increment left array index */
	}
}
