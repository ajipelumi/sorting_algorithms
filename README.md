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

### Bubble Sort Algorithm
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

### Insertion Sort Algorithm
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
