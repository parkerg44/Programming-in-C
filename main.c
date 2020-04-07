/*
Author: Parker Guillen
4/15/18
Description: PA 8
CPTS 121
*/


#include "Header.h"

int main(void)
{
	// PART ONE MY_STR_N_CPY
	char dest1[25] = "lion", source[7] = "hunter";
	my_str_n_cat(dest1, source, 1);
	printf("PART ONE : my_str_n_cpy\n");
	printf("Str_n_copy with n as one: %s\n", dest1);
	char dest2[25] = "lion";
	my_str_n_cat(dest2, source, 3);
	printf("Str_n_copy with n as three: %s\n", dest2);
	char dest3[25] = "lion";
	my_str_n_cat(dest3, source, 6);
	printf("Str_n_copy with n as six: %s\n\n", dest3);

	

	// PART TWO BINARY SEARCH
	int array1[6] = { 1,2,3,4,5,6 }, target_index = -1;
	target_index = binary_search(array1, 6, 5);
	printf("\nPART TWO: Binary Search\n");
	printf("Array of values is:\n");
	for (int i = 0; i < 6; i++)
	{
		printf("%d\t", array1[i]);
	}
	printf("\nValue 5 is found at this index: %d\n\n", target_index);



	//PART THREE BUBBLE SORT
	char *list[5] = { "rat", "ant", "cat", "mouse", "dog"};
	printf("\nPART THREE: Bubble Sort\n");
	//int list[6] = { 9,8,4,3,1,0 };
	printf("List before bubble sort:\n");
	for (int i = 0; i < 5; i++)
	{
		printf("%s\t", list[i]);
	}
	printf("\n");
	bubble_sort(list, 5);
	printf("List after bubble sort:\n");
	for (int i = 0; i < 5; i++)
	{
		printf("%s\t", list[i]);
	}
	printf("\n\n");



	//PART FOUR PALINDROME
	int palindrome_true = 0, test2 = -1, test3 = -1;
	char str[4] = "mom";
	palindrome_true = is_palindrome(str, 0, 3);
	printf("\nPART FOUR:\nPalindrome\nIs 'mom' a palindrome: %d", palindrome_true);
	char str2[8] = "racecar";
	test2 = is_palindrome(str2, 0, 7);
	printf("\nIs 'racecar' a palindrome: %d", test2);
	char str3[9] = "hellosir";
	test3 = is_palindrome(str3, 0, 8);
	printf("\nIs 'hellosir' a palindrome: %d\n\n", test3);



	//PART FIVE SUM PRIMES
	int n = 13, sum = 0,sum2 = 0;
	sum = sum_primes(n);
	printf("\nPART FIVE: Sum primes\nSum of all prime numbers starting at 13 = %d\n", sum);
	sum2 = sum_primes(29);
	printf("Sum of all prime numbers starting at 29 = %d\n\n", sum2);
	



	//PART SIX MAXIMUM_OCCURENCES
	printf("\nPART SIX: Maximum Occurences\n");
	Occurences case1[127] = { {0,0.0} };
	int max_int = -1;
	char str9[25] = "teststring", find = 't'; 
	printf("String being tested is '%s':\n", str9);
	maximum_occurences(str9, &max_int, find, case1);
	printf("Max number of occurences: %d\n\n", max_int);

	return 0;
}