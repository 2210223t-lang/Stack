# Stack

This repository contain useful stack C - realization, which peculiarity is safety.

## Functions

Repo structure:



### Standard usage
Repository contains standard vector functions from c++, such as: push or pop:

1) To call push, use:
> stack_push( stack*, value );
2) To call pop, use:
> stack_pop( stack* );
3) To initialize stack variable:
> stack_init( stack* );
4) To destroy variable:
> stack_destr( stack* );

### Changing storing type

Repository work with int variables, but if you need another type, you can open file: 'config.h' and change typedef value of stack_data on needed.

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

In 'config.h'

Also you can change output stream, to do it, open file 'Debug/lig.h' and change value of logger_filename.

### Details

All debugging functions you can find in 'Debug' folder



