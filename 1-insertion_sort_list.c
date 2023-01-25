#include "sort.h"

/**
 * insertion_sort_list - sorts an array of integers in ascending
 * order using the Insertion sort algorithm
 *
 * @list: pointer to the head of linked list
 *
 * Return: void
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *temp, *current;

	if (!(*list)) /* list is empty */
	{
		return;
	}

	current = *list; /* points to first node */
	while (current->next) /* loop to second to last node */
	{
		/* current node is greater than next node */
		if (current->n > current->next->n)
		{
			temp = current->next; /* point to next node */
			/* if node to be swapped is at index 0 (first node) */
			if (current == *list)
			{
				temp->prev = NULL;
				*list = temp; /* temp becomes first node */
			}
			else /* node to be swapped is not first node */
			{
				current->prev->next = temp;
				temp->prev = current->prev;
			}
			current->next = temp->next;
			current->prev = temp;
			if (temp->next) /* last node not met yet */
			{
				temp->next->prev = current;
			}
			temp->next = current;
			print_list(*list); /* print list */
			current = *list; /* goes back to the head like recursion */
		}
		else
		{
			current = current->next; /* go to the next node */
		}
	}
}
