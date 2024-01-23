#include "sort.h"
/**
 * shell_sort -Sort an array using shell_sort algorithm
 * @array: array
 * @size: size of the array
 * Return: NULL
 **/
void shell_sort(int *array, size_t size)
{
	unsigned int gap = 1, a, k;
	int temp;

	if (array == NULL)
		return;
	if (size < 2)
		return;
	while (gap < size / 3)
		gap = gap * 3 + 1;

	while (gap > 0)
	{
		for (a = gap; a < size; a++)
		{
			temp = array[a];
			k = a;
			while (k >= gap && array[k - gap] > temp)
			{
				array[k] = array[k - gap];
				k -= gap;
			}
			array[k] = temp;
		}
		print_array(array, size);
		gap /= 3;
	}
}
