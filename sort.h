#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */

typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/* print array function */
void print_array(const int *array, size_t size);

/* print list function */
void print_list(const listint_t *list);

/* bubble sort function */
void bubble_sort(int *array, size_t size);

/* insertion sort function */
void insertion_sort_list(listint_t **list);

/* selection sort function */
void selection_sort(int *array, size_t size);

/* quick sort function */
void quick_sort(int *array, size_t size);


#endif
