/*
Author: Parker Guillen
2/4/18
Description: Lesson 3: Scans in data from a student record file and finds many values such as sums, means, variances, standard deviation 
, min, and max and prints results to an outfile.
*/

#include "Lesson_3_header.h"							//Includes the header file
//How can this be done faster and less repetive

int main(void)
{
	FILE*infile = NULL, *outfile = NULL;		//Sets infile and outfile to NULL
	infile = fopen("input.dat", "r");		//Opens the file input.dat for reading as infile
	outfile = fopen("output.dat", "w");		//Opens the file out.dat for writting as outfile

	int studentid1 = 0, standing1 = 0;		//Gathers data from the file for all the records for student 1
	double gpa1 = 0.0, age1 = 0.0; 
	studentid1 = read_integer(infile);
	gpa1 = read_double(infile);
	standing1 = read_integer(infile);
	age1 = read_double(infile);
	
	int studentid2 = 0, standing2 = 0;		//Gathers data from the file for all the records for student 2
	double gpa2 = 0.0, age2 = 0.0;
	studentid2 = read_integer(infile);
	gpa2 = read_double(infile);
	standing2 = read_integer(infile);
	age2 = read_double(infile);
	

	int studentid3 = 0, standing3 = 0;		//Gathers data from the file for all the records for student 3
	double gpa3 = 0.0, age3 = 0.0;
	studentid3 = read_integer(infile);
	gpa3 = read_double(infile);
	standing3 = read_integer(infile);
	age3 = read_double(infile);
	

	int studentid4 = 0, standing4 = 0;		//Gathers data from the file for all the records for student 4
	double gpa4 = 0.0, age4 = 0.0;
	studentid4 = read_integer(infile);
	gpa4 = read_double(infile);
	standing4 = read_integer(infile);
	age4 = read_double(infile);
	
	int studentid5 = 0, standing5 = 0;		//Gathers data from the file for all the records for student 5
	double gpa5 = 0.0, age5 = 0.0;
	studentid5 = read_integer(infile);
	gpa5 = read_double(infile);
	standing5 = read_integer(infile);
	age5 = read_double(infile);


	double gpasum = 0.0, standingsum = 0.0, agesum = 0.0;
	gpasum = calculate_sum(gpa1, gpa2, gpa3, gpa4, gpa5);		//Uses calculate_sum to find the sum of gpa
	standingsum = calculate_sum(standing1, standing2, standing3, standing4, standing5);		//Use calculate_sum to find the sum of the class standing
	agesum = calculate_sum(age1, age2, age3, age4, age5);		//Use calculate_sum to find the sum of ages
	

	double gpamean = 0.0, standingmean = 0.0, agemean = 0.0;
	gpamean = calculate_mean(gpasum, 5);						//Uses calculate_mean to find mean of gpa, class standing, age
	standingmean = calculate_mean(standingsum, 5);
	agemean = calculate_mean(agesum, 5);
	print_double(outfile, gpamean);								//Passes the means to the print_double fuction to print values for age, standing, gpa to output file
	print_double(outfile, standingmean);
	print_double(outfile, agemean);
	

	double gpad1 = 0.0, gpad2 = 0.0, gpad3 = 0.0, gpad4 = 0.0, gpad5 = 0.0;
	gpad1 = calculate_deviation(gpa1, gpamean);					// Uses calculate_deviation to find the deviation for each value of gpa
	gpad2 = calculate_deviation(gpa2, gpamean);
	gpad3 = calculate_deviation(gpa3, gpamean);
	gpad4 = calculate_deviation(gpa4, gpamean);
	gpad5 = calculate_deviation(gpa5, gpamean);

	double variance = 0.0, standard_dev;						// Uses calculate_variance and calculate_standard_deviation to find variance and SD, prints result to output file
	variance = calculate_variance(gpad1, gpad2, gpad3, gpad4, gpad5, 5);
	standard_dev = calculate_standard_deviation(variance);
	print_double(outfile, standard_dev);

	double max1 = 0.0, min1 = 0.0;								// Uses find_min/max to find the min and max values of gpa and prints it to the output file
	max1 = find_max(gpa1, gpa2, gpa3, gpa4, gpa5);
	min1 = find_min(gpa1, gpa2, gpa3, gpa4, gpa5);
	print_double(outfile, min1);
	print_double(outfile, max1);


	fclose(infile);												// Closes the infile
	fclose(outfile);											// Closes the outfile

	system("pause");											// Allows screen to stay up after program is ran
	return 0; 
}
