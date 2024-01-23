#include "sort.h"
/**
 * print_array - Prints an array of integers
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void print_array(const int *array, size_t size)
{
  size_t a;

  for (a =0; array && a < size; ++a)
    {
      if (a > 0)
	printf(", ");
      printf("%d", array[a]);
      ++a;
    }
  printf("\n");
}
