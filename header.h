#ifndef parker_guillen_pa3

/*
Author: Parker Guillen
Description: PA#3, Header file includes function prototypes
CPTS 121
2/8/18
*/

#pragma once

#include <stdio.h>		//Includes studio.h and math.h for use in main and other functions 
#include <math.h>
//Functions prototypes 
double read_double(FILE *infile);
int read_integer(FILE *infile);
double calculate_sum(double number1, double number2, double number3, double number4, double number5);
double calculate_mean(double sum, int number);
double calculate_deviation(double number, double mean);
double calculate_variance(double deviation1, double deviation2, double deviation3, double deviation4, double deviation5, int number);
double calculate_standard_deviation(double variance);
void print_double(FILE *outfile, double number);
double find_max(double number1, double number2, double number3, double number4, double number5);
double find_min(double number1, double number2, double number3, double number4, double number5);


#endif // !parker_guillen_pa3