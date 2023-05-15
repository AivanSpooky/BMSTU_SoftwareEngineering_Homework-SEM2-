#include <stdio.h>
#include <stdbool.h>

#include "consts.h"
#include "funcs.h"

int main(void)
{
    int a[2*N];
    size_t a_size;
    int error = input(a, &a_size);
    switch (error)
    {
        case ERR_IO:
            printf("Массив пуст!\n");
            return error;
            break;
        case ERR_RANGE:
            printf("Длина массива должна быть в диапазоне [1, 10]!\n");
            return error;
            break;
        case ERR_ELEM_IO:
            printf("Некорректный ввод!\n");
            return error;
            break;
    }
    add_digit_count_after_prime(a, &a_size);
    print(a, a_size);
    return OK;
}
