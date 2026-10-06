[![Language](https://img.shields.io/badge/language-C-blue.svg)](https://en.wikipedia.org/wiki/C_(programming_language))

# Stack

This repository contain useful stack C - realization, which peculiarity is safety.

<!-- ## Functions

Repo structure: -->




## Standard usage
Repository contains standard vector functions from c++, such as: push or pop:

1) To call push, use:
> stack_push( stack*, value ) || stack_push_desc( int, value )
2) To call pop, use:
> stack_pop( stack* ) || stack_pop_desc( int )
3) To initialize stack variable:
> stack_init( stack*, int ) || stack_init_desc( int*, int )
4) To destroy variable:
> stack_destr( stack* ) || stack_destr_desc( int* )

### Changing storing type

Repository work with int variables, but if you need another type, you can open file: ```config.h``` and change typedef value of stack_data on needed.

List of supported types:
1) short
2) int
3) double
4) float
5) long long
6) unsigned long long
7) unsigned int
8) unsigned short
9) char
10) string.

## Debugging mode

One of the essential functions of this repository is to display every single process passed into log file.

To turn on this function delete
> #define NO_DEBUG

In ```config.h```

Also you can change output stream, to do it, open file ```Debug/log.h``` and change value of logger_filename.

### Details

All debugging functions you can find in 'Debug' folder.

1. ```Log``` files contain log - output related functions.

2. ```Utility.cpp``` consist of many other useful 3. functions.

3. ```Errors.cpp``` is aimed to handle all types of errors and print useful info.

4. ```hash.cpp``` consist of hashing functions.

Also you can use 2 types of stack - functions ( common ) and common_desc

The former functions return user real stack variables, while the last once hide stack variable and return user only their descriptors.

# Press F to pay respect

[Нетреба Николаю](https://github.com/NikolayNetreba) за помощь в тестировании при разработки этого проекта

[Деду](https://wiki.mipt.tech/index.php/%D0%94%D0%B5%D0%B4%D0%B8%D0%BD%D1%81%D0%BA%D0%B8%D0%B9_%D0%98%D0%BB%D1%8C%D1%8F_%D0%A0%D1%83%D0%B4%D0%BE%D0%BB%D1%8C%D1%84%D0%BE%D0%B2%D0%B8%D1%87)( ┌(・o・)┐  HELP )
