/*
Author: Parker Guillen
1/30/17
Description: Lesson 2, In this lesson the use of Functions will be studied to provide reusable and more readable code
Also the three file format is introduced, a file for the function bodies(source.c), one for the
function defs and includes(header.h) and the final file for main where the actual program is excecuted(main.c)
equations.c file contains all the code for various functions called throughout main.
*/

#include "Lesson_2_Functions.h"		// Includes the header file(include-stdio-prototypes)


//Starting function Definitions

/* 
*Function name: calculate_newtons_2nd_law(mass,accel)
*Date: 1/30/17
*Description: Calculates the force from the user input mass and acceleration.
*Input parameters: double mass, double accel
*Returns: force as a double
*Preconditions: mass and accel must be defined in main function 
*Post conditions: Force is a double.
*/
double calculate_newtons_2nd_law(double mass, double accel) //mass and accel are called parameters 
{							    //the double at the beginning of the functions 
	double force = 0.0;				    //Tells us that this funtion will return a double
	force = mass * accel;
	return force;
}


/*
*Function name: calculate_volume_cylinder(radius,height)
*Date: 1/30/17
*Description: Uses user inputs and constant PI to solve for the volume of a cylinder.
*Input parameters:double radius and double height
*Returns:Volume as a double
*Preconditions: radius and height must be already defined.
*Post conditions: volume is a defined double.
*/
double calculate_volume_cylinder(double radius, double height)
{
	double volume = 0.0;
	volume = PI * radius * radius * height;
	return volume;
}

/* 
*Function name:  perform_character_encoding(plaintext)
*Date: 1/30/17
*Description: Takes a character and encodes it.
*Input parameters: Char plaintext
*Returns: encoded character
*Preconditions: plaintext is defined as a char
*Post conditions: Encoded text is defined as a char.
*/
char perform_character_encoding(char plaintext)
{
	char encodechr;
	encodechr = (plaintext - 'a') + 'A';
	return encodechr;
}

/*
*Function name: calculate_gravity_force()
*Date: 1/31/18
*Description: finds the force using mass1, mass2, distance.
*Input parameters: mass1,mass2, distance
*Returns: gforce
*Preconditions: mass1, mass2, distance must be defined doubles.
*Post conditions: gforce is a defined double
*/
double calculate_gravity_force(double mass1, double mass2, double distance)
{
	double gforce = 0.0;
	gforce = (G * mass1 * mass2) / (distance * distance);
	return gforce;

}

/*
*Function name: calculate_resistive_divider()
*Date: 1/31/18
*Description: Calculates the voltage out from the input values.
*Input parameters: r1, r2, and vin
*Returns: vout
*Preconditions: r1, r2, vin are defined doubles
*Post conditions: vout out is defined as a double
*/
double calculate_resistive_divider(double r1, double r2, double vin)
{	
	double vout = 0.0;
	vout = r2 / ((r1 + r2)*vin);
	return vout;
}

/*
*Function name: calculate_distance_between_2pts
*Date: 1/31/17
*Description: Calculates the distance bewteen two points.
*Input parameters: x1, x2, y1, y2
*Returns: cordsfinal
*Preconditions:  x1, x2, y1, y2 are all defined as doubles
*Post conditions: Cordsfinal is defined as a double
*/
double calculate_distance_between_2pts(double x1, double x2, double y1, double y2)
{
	double cordsfinal = 0.0;
	cordsfinal = sqrt(((x1 - x2)*(x1 - x2)) + ((y1 - y2)*(y1 - y2)));
	return cordsfinal;

}

/*
*Function name: calculate_general_equation()
*Date: 1/31/18
*Description: uses values input by the user
*Input parameters: a, x, z 
*Returns: genfinal
*Preconditions: a,x,z are defined as an int and two double
*Post conditions: genfinal is defined as a double.
*/
double calculate_general_equation(int a, double x, double z)
{
	double genfinal = 0.0;
	genfinal = ((double)89 / 27) - z * x + a / (a % 2);
	return genfinal; 
}
