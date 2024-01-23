#include "sort.h"
/**
 * heapify - Recursively a subtree rooted at index i.
 * @array: Array to sort.
 * @heap_size: Size of the heap.
 * @root_index: Index of the root of the subtree.
 * @size: Size of the array.
 */
void heapify(int *array, int heap_size, int root_index, int size)
{
	int largest = root_index;
	int left_child = 2 * root_index + 1;
	int right_child = 2 * root_index + 2;
	int temp;

	if (left_child < heap_size && array[left_child] > array[largest])
		largest = left_child;

	if (right_child < heap_size && array[right_child] > array[largest])
		largest = right_child;

	if (largest != root_index)
	{
		temp = array[root_index];
		array[root_index] = array[largest];
		array[largest] = temp;
		print_array(array, size);
		heapify(array, heap_size, largest, size);
	}
}
/**
 * heap_sort - Sorts an array using the heap sort algorithm.
 * @array: Array to sort.
 * @size: Size of the array.
 */
void heap_sort(int *array, size_t size)
{
	int i;
	int temp;

	if (array == NULL || size < 2)
		return;
	for (i = size / 2 - 1; i >= 0; i--)
		heapify(array, size, i, size);
	for (i = size - 1; i >= 0; i--)
	{
		temp = array[0];
		array[0] = array[i];
		array[i] = temp;
		if (i > 0)
			print_array(array, size);
		heapify(array, i, 0, size);
	}
}
