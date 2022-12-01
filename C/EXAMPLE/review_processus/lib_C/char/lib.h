#ifndef CHARACTER_CHAIN_H
#define CHARACTER_CHAIN_H

#define DEFAULT_CHARACTER 48

#define EMPTY 1

#define NOTHING -1
#define ERROR -1
#define FALSE 0
#define TRUE 1

// size.c
int __len(unsigned char *str);
unsigned char *__define(unsigned char *str, int size, int strIsEmpty);

// condition.c
int __equal(unsigned char *str0, unsigned char *str1);
int __find(unsigned char *str0, unsigned char *str1);
int __index(unsigned char *str0, unsigned char *str1, int start, int stop);

// modify.c
int __clear(unsigned char *str, unsigned char c);
int __change(unsigned char *str0, unsigned char *str1);
int __append(unsigned char *str, unsigned char c);
int __replace(unsigned char *str0, unsigned char *str1, unsigned char *str2, int start, int stop);
int __replaceAll(unsigned char *str0, unsigned char *str1, unsigned char *str2);

// sizeArray.c
int __lenArray(unsigned char **array);
unsigned char **__defineArray(unsigned char **array, int array_size, int strs_size, int arrayIsEmpty);
int __freeArray(unsigned char **array);

// modifyArray.c
int __clearArray(unsigned char **array, unsigned char c);

// printArray.c
int __printArray(unsigned char **array);

#endif
