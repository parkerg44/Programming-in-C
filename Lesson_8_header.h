#ifndef ParkerGuillenLesson8
/*
Author: Parker Guillen
Description: Lesson 8, header file, function prototypes are listed along with include and define statement.
4/15/18
*/
#include <stdio.h>
#include <math.h>
#include <string.h>

typedef struct occurences
{
	int num_occurences;
	double frequency;
}Occurences;

int binary_search(int *arr, int n, int target);
void *bubble_sort(char *list[], int size);
int is_palindrome(char str[], int start, int size);
int sum_primes(unsigned int n);
char my_str_n_cat(char *dest, const char *source, int n);
void maximum_occurences(char *str, int *integer, char *character, Occurences *occ1 );



#endif // !ParkerGuillenLesson8

