#ifndef __FUNCS_H__

#define __FUNCS_H__

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include "consts.h"

/**
 * @brief Функция ввода массива
 * @details Функция заполняет массив целыми числами, введенными с клавиатуры
 * @param [in] int a[] - массив
 * @param [in] size_t *a_n - указатель на кол-во элементов массива
 * @return Функция возвращает код ошибки
 * @endcode
 * */ 
int input(int a[], size_t *a_size);

/**
 * @brief Функция вывода массива
 * @details Функция выводит элементы массива через пробел
 * @param [in] int a[] - массив
 * @param [in] size_t a_n - кол-во элементов в массиве
 * @return Функция ничего не возвращает
 * @endcode
*/
void print(const int a[], const size_t a_size);

/**
 * @brief Проверка числа на простоту
 * @details Функция проверяет, является ли число простым. Если от 2 до корня из числа есть делитель, то число простое, иначе нет. Все числа меньше 2 простыми не считаются.
 * @param [in] int num - число для проверки
 * @return Функция возвращает признакс простоты (true/false)
 * @endcode
*/
bool is_prime(int num);

/**
 * @brief Функция считает сумму цифр числа
 * @details Функция считает сумму цифр числа, складывая остатки от деления на 10 и деля число, пока остаток не станет равным нулю.
 * @param [in] int n - целое число
 * @return Функция возвращает сумму цифр числа
 * @endcode
*/
int digit_sum(int n);

/**
 * @brief Добавить элемент в массив после указанного индекса
 * @details Функция добавляет новый элемент в массив после переданного индекса.
 * @param [in] int a[] - массив
 * @param [in] size_t *a_size - количество элементов массива
 * @param [in] size_t index - индекс, после которого необходимо добавить элемент
 * @param [in] int new_elem - элемент, который надо добавить
 * @return Функция возвращает код ошибки
 * @endcode
*/
int add_element_after(int a[], size_t *a_size, size_t index, int new_elem);

/**
 * @brief Добавить в массив после каждого простого элемента сумму цифр данного элемента
 * @details Функция добавляет после каждого простого элемента новый элемент численно равный сумме цифр данного простого числа.
 * @param [in] int a[] - массив
 * @param [in] size_t a_size - количество элементов массива
 * @return Функция ничего не возвращает
 * @endcode
*/
void add_digit_count_after_prime(int a[], size_t *a_size);

/**
 * @brief Модульные тесты для модуля is_prime()
 * @return Функция выводит количество ошибок в тестах
 * @endcode
*/
void is_prime_test();

/**
 * @brief Модульные тесты для модуля digit_sum_test()
 * @return Функция выводит количество ошибок в тестах
 * @endcode
*/
void digit_sum_test();

/**
 * @brief Модульные тесты для модуля add_element_after_test()
 * @return Функция выводит количество ошибок в тестах
 * @endcode
*/
void add_element_after_test();

#endif
