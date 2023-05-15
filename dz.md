[[_TOC_]]
# 1. Постановка задачи

## 1.1 условие задачи
```
После каждого элемента целочисленного массива, который является простым числом, вставить новый элемент, равный сумме цифр данного простого числа. Преобразованный массив вывести на экран.
```
## 1.2 допущения

1) Изначальный массив состоит только из целых чисел, которые записаны правильно
2) Изначальных чисел в массиве не более 10
3) Количество  чисел в массиве не более 20
4) При вводе числа разделяются произвольным количеством пробелов
5) Диапазон значений ограничен целым типом
6) Отрицательные числа не считаются простыми

## 1.3 примеры работы

| Ввод     | Вывод    | Код ошибки |
|----------|----------|----------|
| Пустой ввод | Сообщение "Массив пуст!" | 1 |
| a | Сообщение "Массив пуст!" | 1 |
| -1 | Сообщение "Длина массива должна быть в диапазоне [1, 10]!" | 2 |
| 0 | Сообщение "Длина массива должна быть в диапазоне [1, 10]!" | 2 |
| 11 | Сообщение "Длина массива должна быть в диапазоне [1, 10]!" | 2 |
| 2; 1 0.5 | Сообщение "Некорректный ввод!" | 3 |
| 4; 3 + 4 = | Сообщение "Некорректный ввод!" | 3 |
| 3; a b x | Сообщение "Некорректный ввод!" | 3 |
| 3; 1e+50 1 2 | Сообщение "Некорректный ввод!" | 3 |
| 5; 1 2 3 4 41 | 1 2 2 3 3 4 41 5 | 0 |
| 4; (пробелы)1(пробелы)2(пробелы)3 45 | 1 2 2 3 3 45 | 0 |
| 3; 1 4 6 | 1 4 6 | 0 |
| 3; 11 17 19 | 11 2 17 8 19 10 | 0 |
| 3; -2 3 -5 | -2 3 3 -5 | 0 |
| 10; 2 2 2 2 2 2 2 2 2 2 | 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 | 0 |

# 2. Декомпозиция

## 2.1 IDEF0 диаграмма
![01_A-0](uploads/aaa879b1e0c3f7298351c951500d0b9e/01_A-0.png)
![02_A0](uploads/118c6331d3f9b2e2aed9f86ab327b65f/02_A0.png)
![03_A2](uploads/053bb58e4696f4f0cd232b170efb6886/03_A2.png)

## 2.2 спецификации модулей

| 1) Имя модуля | input |
|----------|----------|
| 2) Функция модуля | ввести размер массива и значения элементов массива |
| 3) Список параметров | массив, кол-во эл-тов массива, код ошибки |
| 4) Входные данные | нет |
| 5) Выходные данные | массив, кол-во эл-тов массива, код ошибки |
| 6) Допущения модуля | нет |

| 1) Имя модуля | print |
|----------|----------|
| 2) Функция модуля | вывести элементы массива на экран через пробел |
| 3) Список параметров | массив, кол-во эл-тов массива |
| 4) Входные данные | массив, кол-во эл-тов массива |
| 5) Выходные данные | -нет- |
| 6) Допущения модуля | массив задан корректно |

| 1) Имя модуля | add_digit_count_after_prime |
|----------|----------|
| 2) Функция модуля | добавить в массив после каждого простого элемента сумму цифр этого элемента|
| 3) Список параметров | массив, кол-во эл-тов массива |
| 4) Входные данные | нет |
| 5) Выходные данные | массив, кол-во эл-тов массива |
| 6) Допущения модуля | массив и размерность массива заданы корректно |

| 1) Имя модуля | is_prime |
|----------|----------|
| 2) Функция модуля | определить является ли число простым |
| 3) Список параметров | число, признак |
| 4) Входные данные | число |
| 5) Выходные данные | признак |
| 6) Допущения модуля | диапазон значений ограничен целым типом |

| 1) Имя модуля | digit_sum |
|----------|----------|
| 2) Функция модуля | вернуть сумму цифр числа |
| 3) Список параметров | число, сумма цифр числа |
| 4) Входные данные | число |
| 5) Выходные данные | сумма цифр числа |
| 6) Допущения модуля | передается только простое число |


| 1) Имя модуля | add_elem_after |
|----------|----------|
| 2) Функция модуля | добавить элемент в массив после заданного индекса |
| 3) Список параметров | массив, кол-во эл-тов массива, индекс, новое число |
| 4) Входные данные | индекс, новое число |
| 5) Выходные данные | массив, кол-во эл-тов массива |
| 6) Допущения модуля | массив задан корректно; добавочный элемент является суммой цифр простого числа |


## 2.3 тесты модулей

### input
| Строка ввода | Результат |
|----------|----------|
| Пустой ввод | 1 |
| a | 1 |
| -1 | 2 |
| 0 | 2 |
| 11 | 2 |
| 2; 1 0.5 | 3 |
| 4; 3 + 4 = | 3 |
| 3; a b x | 3 |
| 3; 1e+50 1 2 | 3 |
| 5; 1 2 3 4 41 | 0 |
| 4; (пробелы)1(пробелы)2(пробелы)3 45 | 0 |

### print
| Массив | Результат |
|----------|----------|
| 1\ 1 | 1 |
| 3\ 1 -4 6 | 1[ ]-4[ ]6 |

### is_prime
| Число | Результат |
|----------|----------|
| -11 | false |
| 0 | false |
| 1 | false |
| 4 | false |
| 2 | true |

### digit_sum
| Число | Результат |
|----------|----------|
| 2 | 2 |
| 11 | 2 |

### add_elem_after
| Массив; кол-во; индекс; число | Результат |
|----------|----------|
| [2, 3]; 2; 0; 2 | [2, 2, 3]; 3; |
| [2, 2, 3]; 3; 2; 3 | [2, 2, 3, 3]; 4; |
| [1, 22, 31]; 3; 2; 4 | [1, 22, 31, 4]; 4; |

# 3 Псевдокод модулей
## 3.1 Псевдокод модулей
### модуль input

Вход:

-нет-

Выход:
1) a[2*N] - массив
2) a_size - кол-во эл-тов массива
3) rc - код ошибки
```
rc = 0
вводим a_size
если a_size не число
    rc = 1
если a_size <= 0 или a_size > N
    rc = 2
все если
i = 0
пока i < a_size
    ввести элемент в a[i]
    если a[i] не целое число
        rc = 3
    все если
    i++
все пока
```

### модуль print

Вход:
1) a[2*N] - массив
2) a_size - кол-во эл-тов массива

Выход:
-нет-
```
i = 0
пока i < a_size
    вывести элемент a[i]
    вывести пробел
    i++
все пока
вывести переход на новую строку
```

### модуль add_digit_count_after_prime

Вход:
1) a[2*N] - массив
2) a_size - кол-во эл-тов массива

Выход:
1) a[2*N] - массив
2) a_size - кол-во эл-тов массива
```
i = 0
пока i < a_size
    если is_prime(a[i])
        add_elem_after(a, a_size, i, digit_sum(a[i]))
        i++
все пока
```
### модуль is_prime

Вход:
1) n - число

Выход:
1) prime(true/false) - признак
```
prime = true
если n <= 1
    prime = false
все если
i = 2
пока i <= sqrt(n)
    если n % i == 0
        prime = false
    все если
    i++
все пока
prime = true
```

### модуль digit_sum

Вход:
1) n - число

Выход:
1) sum - сумма цифр
```
пока n != 0
    sum += n % 10
    n /= 10
все пока
```

### модуль add_elem_after

Вход:
1) a[2*N] - массив
2) a_size - кол-во эл-тов массива
3) ind -  индекс
4) n - новое число

Выход:
1) added(true/false) - признак успешного добавления
```
added = true
если ind >= a_size
    added = false
все если
i = a_size-1
пока i >= index
    a[i] = a[i-1]
все for
a[ind+1] = n
a_size++
```
## 3.2 псевдокод основной программы
```
Ввод: -нет-
Выход: -нет-

error = input(a, a_size)
если !error 
    если error == 1
        напечатать сообщение "Массив пуст!"
    если error == 2
        напечатать сообщение "Длина массива должна быть в диапазоне [1, 10]!"
    иначе error == 3
        напечатать сообщение "Некорректный ввод!"
    все если
все если
add_digit_count_after_prime
print(a, a_size)
```
Примечания:
1) a[2*N] - массив
2) a_size - кол-во эл-тов массива
3) error - код ошибки
4) i - индекс