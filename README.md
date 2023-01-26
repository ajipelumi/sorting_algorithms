<img src="https://user-images.githubusercontent.com/106672692/214717924-d21f036f-4770-42bb-9b2a-761cb2407ee9.gif" alt="integer sort" width="300">
Image Credit: Pinterest

##

A **Sorting Algorithm** is used to rearrange a given array or list of elements according to a comparison operator on the elements.
The comparison operator is used to decide the new order of elements in the respective data structure.

### Big O Notation

**Big O Notation** is a *relative* *representation* of the *complexity* of an algorithm.
- **relative**: You can only compare apples to apples. 
You can't compare an algorithm that does arithmetic multiplication to an algorithm that sorts a list of integers.
But a comparison of two algorithms to do arithmetic operations (one multiplication, one addition) will tell you something meaningful;
- **representation**: Big O (in its simplest form) reduces the comparison between algorithms to a single variable. 
That variable is chosen based on observations or assumptions. 
For example, sorting algorithms are typically compared based on comparison operations (comparing two nodes to determine their relative ordering).
This assumes that comparison is expensive. But what if the comparison is cheap but swapping is expensive? It changes the comparison;
- **complexity**: if it takes me one second to sort 10,000 elements, how long will it take me to sort one million?
Complexity in this instance is a relative measure to something else.

This project is a C implementation **Sorting Algorithms** and their time complexity.

## Bubble Sort Algorithm
The `bubble_sort` function takes in an array of integers and its size as arguments. 
It first checks if the array has less than 2 elements or if the array is NULL, in which case it returns without doing anything.

Otherwise, it iterates over the array for *(size - 1)* times, using two nested for loops.
In each iteration, it compares the current element with the next one. If the current element is greater than the next, it swaps them and updates a flag variable to indicate that a swap occurred.
It also calls the `print_array` function to print the current state of the array. 
After each outer loop iteration, if the flag variable is still 0, it means that no swaps occurred, and the array is already sorted, so the function breaks out of the loop.

**Time Complexity**
- in the best case `O(n)`
- in the average case `O(n^2)`
- in the worst case `O(n^2)`

## Insertion Sort Algorithm
The `insertion_sort_list` function takes in a pointer to the head of the linked list as an argument. 
It first checks if the list is empty or the pointer is null, in which case it returns without doing anything.

Otherwise, it sets a pointer *current* to the first node of the linked list.
It then enters a while loop that continues until the last node of the list is reached.
In each iteration of the loop, it compares the value of the current node with the value of the next node.
If the current node's value is greater than the next node's value, it performs a swap of the two nodes' positions by adjusting the pointers.

It also checks if the node to be swapped is at the first index and if it is, it updates the head pointer and the prev pointer of the new first node.
After swapping the nodes, it calls the `print_list` function to print the current state of the list.
It then sets the current pointer back to the head of the list, like recursion. 
If the current node's value is less than or equal to the next node's value, the current pointer is moved to the next node, and the next iteration of the loop begins.

**Time Complexity**
- in the best case `O(n)`
- in the average case `O(n^2)`
- in the worst case `O(n^2)`

## Selection Sort Algorithm
The `selection_sort` function takes in an array of integers and its size as arguments.
It first checks if the array has less than 2 elements or if the array is NULL, in which case it returns without doing anything.

Otherwise, it uses two nested for loops to iterate through the array.
In the outer loop, it starts from the first element and in each iteration, it saves the current element in a temporary variable and sets the current index as the index of the smallest number found so far.
In the inner loop, it starts from the next element of the outer loop and compares it with the temporary variable.
If it finds a number smaller than the temporary variable, it updates the temporary variable with the new smaller number and the index variable with the index of the new smaller number.

At the end of the inner loop, it checks if the index variable has changed from its initial value, if it has, it swaps the element at that index with the current element and calls the `print_array` function to print the current state of the array.
After the outer loop completes, the array will be sorted in ascending order.

**Time Complexity**
- in the best case `O(n^2)`
- in the average case `O(n^2)`
- in the worst case `O(n^2)`

## Quick Sort Algorithm
The `quick_sort` function takes in an array of integers and its size as arguments.
It first checks if the array is empty or has less than 2 elements, in which case it returns as there is no need to sort the array.
It then checks if the array has identical elements, in which case it also returns as there is no need to sort identical elements.

If the array is not empty and has distinct elements, the function initializes the start and end indices and calls the `sort` function.
The `sort` function is a recursive function that takes in the array, start index, end index, and size as arguments.
It first checks if the start index is greater than or equal to the end index, in which case it returns as this is the base case.
If not, it calls the `partition` function which partitions the array using a pivot element and returns the partitioned index.
The function then recursively calls itself with the partitioned index and size as arguments to sort the array.

The `partition` function takes in the array, low index, high index, and size as arguments.
It sets the last element of the array as the pivot element and creates an index variable to track the items in the array.
It then iterates through the array and compares each element with the pivot element.
If the element is less than the pivot, it swaps it with the item at the index and increases the index by 1.
It then swaps the pivot element with the item at the index and returns the partitioned index.

The `swap` function is a helper function that takes in two integers as arguments and swaps their values.

**Time Complexity**
- in the best case `O(nlog(n))`
- in the average case `O(nlog(n))`
- in the worst case `O(n^2)`

## Shell Sort Algorithm
`Shell sort` is a sorting algorithm that sorts an array by comparing elements that are far apart from each other and sorting them.
The `shell_sort` function sorts the array by first determining a gap value and then repeatedly sorting sublists of the array that are separated by the gap value. 
It swaps the elements that are out of order and print the array after each swap till the array is sorted.

**No big O notations of the time complexity of the Shell Sort (Knuth sequence) Algorithm as the complexity is dependent on the size of array and gap.**

## Cocktail Shaker Sort Algorithm
The **Cocktail Shaker Sort Algorithm** algorithm is a variation of the Bubble Sort algorithm,
where the list is iterated through in both directions (forwards and backwards) in order to bubble up the largest element to the end and the smallest element to the front.
The `cocktail_sort_list` function takes in a pointer to the head of the linked list, and sorts the list in ascending order.
Cocktail uses a flag to check if the list is already sorted, and if so, the loop breaks.
Cocktail also uses several helper functions: `swap`, `swap_last`, and `get_last_node` to assist in swapping nodes in the list and getting the last node in the list.

**Time Complexity**
- in the best case `O(n)`
- in the average case `O(n^2)`
- in the worst case `O(n^2)`

## Counting Sort Algorithm
The `counting_sort` function first checks if the array is NULL or has less than 2 elements, in which case it does not need to be sorted, and returns.
It then calls the helper function `get_max` to determine the maximum value in the array.
It then creates two arrays, *count* and *position*, and initializes all elements in count to 0.
It then iterates through the input array and increments the count of each element.
It then iterates through the count array, incrementing each element by the previous element, and printing the result.
It then iterates through the input array again, storing each element in its correct position in the position array.
Finally, it copies the position array into the input array and frees both the count and position arrays.

**Time Complexity**
- in the best case `O(n+k)`
- in the average case `O(n+k)`
- in the worst case `O(n+k)`

## Merge Sort Algorithm
The `merge_sort` function first checks if the array needs to be sorted (i.e. if its size is less than 2 or if the array is NULL) and returns if it doesn't. 
Otherwise, it calls the `divide` function which recursively divides the array into two halves until the base case of a single element is reached.
Then it calls the `merge` function which merges the left and right halves of the array in a sorted order.
The `merge_print` function is called within `merge` to print the left and right arrays as the merging takes place.
The `merge_items` function is also called within `merge` to merge any remaining items in both the left and right arrays.
Finally, the `free` function is called to free the memory allocated for the left and right arrays.

**Time Complexity**
- in the best case `O(nlog(n))`
- in the average case `O(nlog(n))`
- in the worst case `O(nlog(n))`

## Radix Sort Algorithm
The `radix_sort` function takes in two parameters: an array of integers, and the size of the array.
It first checks if the array is empty or has a size less than 2, in which case it returns without doing anything.
If the array has a size of 2, it calls a separate function, `sort_array_size_2` to sort the array, and then prints the array.

If the array has a size greater than 2, the function gets the maximum integer in the array by calling the `get_max` function.
The function then iterates through the digits of the maximum integer, and for each digit, it calls the `count_sort` function to sort the array based on that digit.
After each iteration, the function prints the array.

## Authors
- Ajisafe Oluwapelumi [@ajipelumi](https://github.com/ajipelumi)
