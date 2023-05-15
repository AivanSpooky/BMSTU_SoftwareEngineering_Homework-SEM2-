#include "funcs.h"

int input(int a[], size_t *a_size)
{
	printf("Input n: ");
	if (scanf("%zu", a_size) != 1)
		return ERR_IO;
	if (*a_size == 0 || *a_size > N)
		return ERR_RANGE;
	printf("Input elems: ");
	for (size_t i = 0; i < *a_size; i++)
	{
		if (scanf("%d", &a[i]) != 1)
			return ERR_ELEM_IO;
	}
	return OK;
}

void print(const int a[], const size_t a_n)
{
	printf("\nArray: \n");
	for (size_t i = 0; i < a_n; i++)
		printf("%d ", a[i]);
	printf("\n");
}
