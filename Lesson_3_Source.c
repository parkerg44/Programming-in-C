/*
Author: Parker Guillen
2/04/18
Description: Lesson 3, header file, function prototypes are listed along with include and define statement.
*/

#include "header.h"


/*
*Function name: read_double(FILE *infile)
*Date: 2/8/18
*Description: Reads a double from the input file
*Input parameters: infile
*Returns: numberd (number double)
*Preconditions: numnberd must be defined as a double, infile msut be open for reading
*Post conditions: numberd must be defined as a double
*/
double read_double(FILE *infile)		//* = pointer will be reviewed later
{
	double numberd = 0.0;
	fscanf(infile, "%lf", &numberd);	//fscanf used to read from a file in C
	return numberd;

}


/*
*Function name: read_integer(FILE *infile)
*Date: 2/8/18
*Description: Reads a int from the input file
*Input parameters: infile
*Returns: numberi (number int)
*Preconditions: numnberd must be defined as an int, infile msut be open for reading
*Post conditions: numberd must be defined as a int
*/
int read_integer(FILE *infile)
{
	int numberi = 0;
	fscanf(infile, "%d", &numberi);
	return numberi;

}


/*
*Function name:  calculate_sum(double number1, double number2, double number3, double number4, double number5)
*Date: 2/8/18
*Description: Calculates and returns the sum from five number inputs
*Input parameters: number1, number2, number3, number4, number5
*Returns: dsum (double sum)							
*Preconditions: all actual arguments must be defined 
*Post conditions: dsum must be defined within the function 
*/
double calculate_sum(double number1, double number2, double number3, double number4, double number5)
{
	double dsum = 0.0;
	dsum = number1 + number2 + number3 + number4 + number5;
	return dsum; 

}


/*
*Function name: calculate_mean(double sum, int number)
*Date: 2/8/18													
*Description: Calculates the mean from the input sum and number
*Input parameters: sum, number
*Returns:meant (mean test)
*Preconditions: sum and number must be defined
*Post conditions: numberd must be defined as a int
*/
double calculate_mean(double sum, int number)
{
	double meant = 0.0;
	meant = sum / number;
	return meant;

}


/*
*Function name: calculate_deviation(double number, double mean)
*Date: 2/8/18
*Description: calculates the deviation from the mean and the choosen number.
*Input parameters: number, mean
*Returns: deviationt (deviation test)
*Preconditions: number and mean are defined as doubles
*Post conditions: deviationt is returned as double
*/
double calculate_deviation(double number, double mean)
{
	double deviationt = 0.0;
	deviationt = number - mean; 
	return deviationt; 

}


/*
*Function name: calculate_variance(double deviation1, double deviation2, double deviation3, double deviation4, double deviation5, int number)
*Date: 2/8/18
*Description: Calculates the variance from the gpa deviation numbers
*Input parameters: deviation1, deviation2, deviation3, deviation4, deviation5
*Returns: variancet (variance test)
*Preconditions: All deviations must be defined, math.h must be included
*Post conditions: variancet must be returned as a double
*/
double calculate_variance(double deviation1, double deviation2, double deviation3, double deviation4, double deviation5, int number)
{
	double variancet = 0.0;
	variancet = (pow(deviation1, 2) + pow(deviation2, 2) + pow(deviation3, 2) + pow(deviation4, 2) + pow(deviation5, 2)) / number;
	return variancet; 

}


/*
*Function name: double calculate_standard_deviation(double variance)
*Date: 2/8/18
*Description: calculates standard deviation from the variance
*Input parameters: variance
*Returns: stand_dev
*Preconditions: stand_dev must be defined as an double
*Post conditions: stand_dev must be defined as a double
*/
double calculate_standard_deviation(double variance)
{
	double stand_dev = 0.0;
	stand_dev = sqrt(variance);
	return stand_dev; 
}


/*
*Function name: void print_double(FILE *outfile, double number)
*Date: 2/8/18
*Description: Prints a double number to the outfile
*Input parameters: outfile, number
*Returns: None 
*Preconditions: the number printed must be a double, outfile must be open for writting
*Post conditions: None
*/
void print_double(FILE *outfile, double number)
{
	fprintf(outfile, "%.2lf\n", number);
}


/*
*Function name: double find_max(double number1, double number2, double number3, double number4, double number5)
*Date: 2/8/18
*Description: Uses if statements to find the max value from the gpa
*Input parameters: number1, number2, number3, number4, number5
*Returns: max
*Preconditions: max must be defined as a double
*Post conditions: max must be defined as a double
*/
double find_max(double number1, double number2, double number3, double number4, double number5)
{
	double max = number1; 
	if (number2 > max)
	{
		max = number2;
	}
	if (number3 > max)
	{
		max = number3;
	}
	if (number4 > max)
	{
		max = number4;
	}
	if (number5 > max)
	{
		max = number5;
	}
	return max; 
}


/*
*double find_min(double number1, double number2, double number3, double number4, double number5)
*Date: 2/8/18
*Description: uses if statements to find the min value of the gpa
*Input parameters: number1, number2, number3, number4, number5
*Returns: min
*Preconditions: min must be defined as a double.
*Post conditions: min must be defined as a double
*/
double find_min(double number1, double number2, double number3, double number4, double number5)
{
	double min = number1; 
	if (number2 < min)
	{
		min = number2;
	}
	if (number3 < min)
	{
		min = number3;
	}
	if (number4 < min)
	{
		min = number4;
	}
	if (number5 < min)
	{
		min = number5;
	}
	return min;

}

//End of Source file
