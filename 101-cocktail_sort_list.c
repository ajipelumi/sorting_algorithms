#include "sort.h"

void swap(listint_t *current, listint_t **list);
void swap_last(listint_t *last, listint_t **list);
listint_t *get_last_node(listint_t **list);

/**
 * cocktail_sort_list - sorts an array of integers in ascending
 * order using the Cocktail shaker sort algorithm
 *
 * @list: pointer to the head of linked list
 *
 * Return: void
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *current, *last;
	int flag = 1;

	if (!list || !*list) /* list is empty */
	{
		return;
	}
	while (flag == 1)
	{
		current = *list; /* points to head of list */
		flag = 0;
		while (current->next) /* iterate through list */
		{
			/* if current node is greater than next node */
			if (current->n > current->next->n)
			{
				swap(current, list); /* call swap */
				print_list(*list); /* print list */
				flag = 1; /* flag is updated */
			}
			current = current->next;
		}
		if (flag == 0) /* list is sorted */
		{
			break;
		}
		flag = 0;
		last = get_last_node(list); /* get last node */
		while (last->prev)
		{
			/* if current node is less than previous node */
			if (last->n < last->prev->n)
			{
				swap_last(last, list); /* call swap */
				print_list(*list); /* print list */
				flag = 1; /* flag is updated */
			}
			last = last->prev;
		}
	}
}

/**
 * swap - swaps nodes
 *
 * @current: pointer to current node
 * @list: pointer to the head of linked list
 *
 * Return: void
 */

void swap(listint_t *current, listint_t **list)
{
	listint_t *temp;

	/* temp points to the next node to be swapped with */
	/* while current still points to the current node */
	temp = current->next;
	if (current == *list) /* if current is the head of list */
	{
		temp->prev = NULL; /* temp prev should point to NULL */
		*list = temp; /* temp is now head of the list */
	}
	else /* if current node is not head of the list */
	{
		/* the previous node before current should have it next point to temp */
		current->prev->next = temp;
		/* temp should also have its prev point to that previous node */
		temp->prev = current->prev;
	}
	/* current next should now point to the next of temp */
	current->next = temp->next;
	/* current prev should now point to temp */
	current->prev = temp;

	if (temp->next) /* if temp happens to be the last node on the list */
	{
		/* the next of temp should have it prev point to current */
		temp->next->prev = current;
	}

	/* temp next should now point current */
	temp->next = current;
}

/**
 * swap_last - swaps nodes
 *
 * @last: pointer to last node
 * @list: pointer to the head of linked list
 *
 * Return: void
 */

void swap_last(listint_t *last, listint_t **list)
{
	listint_t *temp;

	/* temp points to the previous node to be swapped */
	/* while last still points to the current node on the list */
	temp = last->prev;
	if (temp == *list) /* if the previous node is the list head */
	{
		last->prev = NULL; /* the current node prev will now be NULL */
		*list = last; /* last is now the head of the list */
	}
	else /* if the previous node is not the head of the list */
	{
		/* the prev of temp should have its next point to the current node */
		temp->prev->next = last;
		/* last should also have its prev point to that prev */
		last->prev = temp->prev;
	}
	/* temp next should be current/last next */
	temp->next = last->next;
	/* temp prev should point to current/last */
	temp->prev = last;

	if (last->next) /* if current/last node is not the last on the list */
	{
		/* the next of last should have its prev point to temp */
		last->next->prev = temp;
	}
	/* last next now points to temp */
	last->next = temp;
}

/**
 * get_last_node - gets the last node in a list
 *
 * @list: pointer to the head of linked list
 *
 * Return: pointer to the last node
 */

listint_t *get_last_node(listint_t **list)
{
	listint_t *temp;

	temp = *list;
	while (temp->next) /* iterate through list */
	{
		temp = temp->next;
	}
	return (temp); /* returns last node */
}
