/* Author: Parker Guillen
1/30/17
Description: Lesson 2, header file, function prototypes are listed along with include and define statement.
*/         

//it is good practice to place all includes/defines in the header file
#include <stdio.h> //printf() and scanf()
#include <math.h>
#define PI 3.14159	// Defines PI as 3.14159
#define G 6.67e-11	// Defines G 6.67e-11

// Function prototypes: These are the names of the functions within the source file 
// if using the three file format the function prototypes must first be defined in the header
double calculate_newtons_2nd_law(double mass, double accel);
double calculate_volume_cylinder(double radius, double height);
char perform_character_encoding(char plaintext);
double calculate_gravity_force(double mass1, double mass2, double distance);
double calculate_resistive_divider(double r1, double r2, double vin);
double calculate_distance_between_2pts(double x1, double x2, double y1, double y2);
double calculate_general_equation(int a, double x, double z);

//End of Header File
