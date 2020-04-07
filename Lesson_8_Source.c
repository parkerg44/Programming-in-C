/*
Author: Parker Guillen
4/15/18
Description: Lesson 8 source files for functions
CPTS 121
*/
#include "Lesson_8_header.h"

/*

*/
int binary_search(int *arr, int n, int target)
{
	int left = 0, right = n - 1, mid = 0, found = 0;
	while (found == 0 && left <= right)
	{
		mid = (left + right) / 2;
		if (target == arr[mid])
		{
			found = 1;
		}
		if (target < arr[mid])
		{
			right = mid - 1;
		}
		if (target > arr[mid])
		{
			left = mid + 1;
		}
	}
	int target_index = -1;
	if (found == 1)
	{
		target_index = mid;
	}
	return target_index;
}

/*

*/
void *bubble_sort(char *list[], int size)
{
	int index = 0, passes = 0;
	char *temp = 0;
	
	passes = 1;
	while (passes < size)
	{
		index = 0;
		while (index < size - passes)
		{
			if ((strcmp(list[index], list[index + 1]) > 0))
			{
				temp = list[index];
				list[index] = list[index + 1];
				list[index + 1] = temp;
			}
			/*else if ((strcmp(list[index], list[index + 1]) < 0))
			{
				temp = list[index + 1];
				list[index + 1] = list[index];
				list[index] = temp;
			}*/
			index++;
		}
		passes++;
	}




	//int index = 0, temp = 0, passes = 0;
	//passes = 1;
	//while (passes < size)
	//{
	//	index = 0;
	//	while (index < size - passes)
	//	{
	//		if (list[index] > list[index + 1])
	//		{
	//			temp = list[index];
	//			list[index] = list[index + 1];
	//			list[index + 1] = temp;
	//		}
	//		index++;
	//	}
	//	passes++;
	//}
	
}

/*

*/
int is_palindrome(char str[], int start, int size)
{
	size = size - 1;
	if (str[start] == str[size])
	{
		return 1;
	}
	else if (str[start] == str[size])
	{
		return is_palindrome(str, start + 1, size - 1);
	}
	else
	{
		return 0;
	}
}


/*

*/
int sum_primes(unsigned int n)
{
	if (n == 2)
	{
		return 2;
	}

	else
	{
		int numnotprime = 0, prime = 0;
		for (int i = 2; i < n; i++)
		{
			if (n % i == 0)
			{
				numnotprime++;
			}
			else
			{
				prime++;
			}
		}
		if (numnotprime != 0)
		{
			return 0 + sum_primes(n - 1);
		}
		else
		{
			return n + sum_primes(n - 1);
		}
	}
}

/*

*/
char my_str_n_cat(char *dest, const char *source,int n)
{
	int length = 0;
	//char dest1; 
	//dest = dest1;
	while (*dest)
	{
		++length;
		++dest;
	}

	//dest = dest + length;
	/*if (n > 1)
	{
		n -= 1;
	}*/
	for (int i = 0; i < n; i++)
	{
		//while (*source != '\0')
		//{
		*dest = *source;
		dest++;
		source++;
		//}
	}
	*dest = '\0';
	return dest;
}

void maximum_occurences(char *str, int *integer, char *character, Occurences *occ1)
{
	int strlength = 0, charcount = 0;
	strlength = strlen(str);
	for (int i = 0; i < strlength; i++)
	{
		occ1[str[i]].num_occurences = occ1[str[i]].num_occurences + 1;
	}
	for (int j = 97; j < 123; j++)
	{
		if (occ1[j].num_occurences == 0)
		{
			occ1[j].frequency = 0;
		}
		else
		{
			occ1[j].frequency =(occ1[j].num_occurences / (double)strlength);
			printf("Letter: %c\tOccurences: %d\tFrequency: %lf\n", (char)j ,occ1[j].num_occurences, occ1[j].frequency);
		}
	}
	for (int k = 97; k < 123; k++)
	{
		if (occ1[k].num_occurences > *integer)
		{
			*integer = occ1[k].num_occurences;
		}

	}

	


}
