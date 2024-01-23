#include "sort.h"
/**
 * radix_sort - sorts an array following the Radix sort algorithm
 * @array: array of ints to sort
 * @size: size of the array
 */
void radix_sort(int *array, size_t size)
{
	int max;
	size_t i, lsd;

	if (!array || size < 2)
		return;
	max = 0;
	for (i = 0; i < size; i++)
		if (array[i] > max)
			max = array[i];
	for (lsd = 1; max / lsd > 0; lsd *= 10)
	{
		count_sort_LSD(array, size, lsd);
		print_array(array, size);
	}
}
/**
 * count_sort_LSD - count sort with LSD
 * @array: array to sort
 * @size: size of the array
 * @lsd: least significant digit
 */
void count_sort_LSD(int *array, size_t size, size_t lsd)
{
	int count_arr[10] = {0}, *out_arr, index, count,
	    output_index, input_index;

	out_arr = malloc(sizeof(int) * size);

	for (input_index = 0; input_index < size; input_index++)
		count_arr[(array[input_index] / lsd) % 10]++;
	for (index = 1; index < 10; index++)
		count_arr[index] += count_arr[index - 1];
	for (output_index = size - 1; output_index >= 0; output_index--)
	{
		out_arr[count_arr[(array[output_index] / lsd) % 10] - 1] =
			array[output_index];
		count_arr[(array[output_index] / lsd) % 10]--;
	}
	for (input_index = 0; input_index < size; input_index++)
		array[input_index] = out_arr[input_index];
	free(out_arr);
}
