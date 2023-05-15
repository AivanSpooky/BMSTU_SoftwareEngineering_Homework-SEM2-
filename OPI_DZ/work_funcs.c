#include "funcs.h"

bool is_prime(int num)
{
	if (num <= 1)
		return false;
	for (int i = 2; i <= sqrt(num); i++)
		if (num % i == 0)
			return false;
	return true; 
}

void is_prime_test()
{
	printf("is_prime_test:\n");
	int counter = 0;
	/*
	Число меньше 0
	*/
	if (is_prime(-11) != false)
	{
		printf("neg_01_in: FAIL\n");
		counter++;
	}
	else
		printf("neg_01_in: PASS\n");
	/*
	Число 0
	*/
	if (is_prime(0) != false)
	{
		printf("neg_02_in: FAIL\n");
		counter++;
	}
	else
		printf("neg_02_in: PASS\n");
	/*
	Число 1
	*/
	if (is_prime(1) != false)
	{
		printf("neg_03_in: FAIL\n");
		counter++;
	}
	else
		printf("neg_03_in: PASS\n");
	/*
	Составное число, большее 1
	*/
	if (is_prime(4) != false)
	{
		printf("neg_04_in: FAIL\n");
		counter++;
	}
	else
		printf("neg_04_in: PASS\n");
	/*
	Простое число
	*/
	if (is_prime(2) != true)
	{
		printf("pos_01_in: FAIL\n");
		counter++;
	}
	else
		printf("pos_01_in: PASS\n");
	printf("ERRORS count: %d\n", counter);
}

int digit_sum(int n)
{
	assert((is_prime(n)));
	int result = 0;
	int num = abs(n);
	while (num % 10 != 0)
	{
		result += num % 10;
		num /= 10;
	}
	return result;
}

void digit_sum_test()
{
	printf("\ndigit_sum_test:\n");
	int counter = 0;
	/*
	Однозначное число
	*/
	if (digit_sum(2) != 2)
	{
		printf("pos_01_in: FAIL\n");
		counter++;
	}
	else
		printf("pos_01_in: PASS\n");
	/*
	Двузначное число
	*/
	if (digit_sum(11) != 2)
	{
		printf("pos_02_in: FAIL\n");
		counter++;
	}
	else
		printf("pos_02_in: PASS\n");
	
	printf("ERRORS count: %d\n", counter);
}

int add_element_after(int a[], size_t *a_size, size_t index, int new_elem)
{
	if (index >= *a_size)
		return ERR_RANGE;
	assert((new_elem == digit_sum(a[index])));
	assert(((*a_size) <= 2*N));
	for (size_t i = *a_size; i > index; i--)
		a[i] = a[i - 1];
	a[index + 1] = new_elem;
	(*a_size)++;
	return OK;
}

void add_element_after_test()
{
	printf("\nadd_element_after_test:\n");
	int counter = 0;
	/*
	Индекс находится за пределами массива (больше размерности)
	*/
	int a1[2*N] = {1, 2, 3};
	size_t a_size = 3;
	size_t index = 10;
	int new_elem = 3; 
	if (add_element_after(a1, &a_size, index, new_elem) != ERR_RANGE)
	{
		printf("neg_01_in: FAIL\n");
		counter++;
	}
	else
		printf("neg_01_in: PASS\n");
	/*
	Добавить элемент после первого числа
	*/
	int a2[2*N] = {11, 2, 3};
	a_size = 3;
	index = 0;
	new_elem = 2; 
	if (add_element_after(a2, &a_size, index, new_elem) != OK)
	{
		printf("pos_01_in: FAIL\n");
		counter++;
	}
	else
		printf("pos_01_in: PASS\n");
	/*
	Добавить элемент после последнего числа
	*/
	int a3[2*N] = {11, 2, 17};
	a_size = 3;
	index = 2;
	new_elem = 8; 
	if (add_element_after(a3, &a_size, index, new_elem) != OK)
	{
		printf("pos_02_in: FAIL\n");
		counter++;
	}
	else
		printf("pos_02_in: PASS\n");
	printf("ERRORS count: %d\n", counter);
}

void add_digit_count_after_prime(int a[], size_t *a_size)
{
	for (size_t i = 0; i < (*a_size); i++)
        if (is_prime(a[i]))
        {
            add_element_after(a, a_size, i, digit_sum(a[i]));
            i++;
        }
}

