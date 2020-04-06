/* Author: Parker Guillen
   1/20/17
   Description: PA 1, Asks the user for many different values to be used in various equations.
   Collaborators: Professor's Fallons code from class for encoding character*/
#include <stdio.h> //printf() and scanf()
#include <math.h>
#define PI 3.14159	// Defines PI as 3.14159
#define G 6.67e-11	// Defines G 6.67e-11
int main(void)
{
	double mass = 0.0, accel = 0.0, force = 0.0;	// Step 1, Problem 1: sets the values for mass, accel, force as doubles
	printf("Enter the mass and acceleration (Both float point values) for use in Newton's second law:\n "); 
	scanf("%lf%lf", &mass, &accel); // Gets inputs from the user for mass and acceleration
	force = mass * accel;	// Uses the formula to find force 
	printf("Newton's Second Law: Force = Mass * Accelertion = %lf * %lf = %lf\n\n ", mass, accel, force); // Prints out the values and force

	double radius = 0.0, height = 0.0, volume = 0.0; //Step 2, Problem 2: Sets values as doubles for radius, height, and volume
	printf("Enter the radius and height (Both float point values) for use to find the volume of a cylinder:\n ");
	scanf("%lf%lf", &radius, &height); // Scans in the values from the user. 
	volume = PI * radius * radius * height; // Uses the constant PI and other variables to find the volume
	printf("Volume of a cylinder = PI * radius^2 * height = %lf * %lf^2 * %lf = %lf\n\n", PI, radius, height, volume);

	char character = 'a', plaintext = '\0', encodechr = '\0'; // Step 3, problem 3: Assigns plaintext and encodechr to empty char 
	printf("Enter a plaintext character: ");	// Prompts user for a plaintext character
	scanf(" %c", &plaintext);	// Scans in value from the user, the space allows the user to input a character
	encodechr = (plaintext - 'a') + 'A';	// Follows equation from class website
	printf("Encoded Character: %c\n\n", encodechr);	

	double mass1 = 0.0, mass2 = 0.0, distance = 0.0, gforce = 0.0; // Step 4, problem 4: find force from mass, distance, and gravity
	printf("Enter the first mass, second mass, and the distance (All float point values) for use in finding force:\n");
	scanf("%lf%lf%lf", &mass1, &mass2, &distance); //Scans in the values from the user for mass1, mass2, and distance
	gforce = (G * mass1 * mass2) / (distance * distance); // Uses the given equations to find the force
	printf("Force = G * mass1 * mass2 / distance^2 = %.13lf * %lf * %lf / %lf^2 = %.13lf\n\n", G, mass1, mass2, distance, gforce);

	double r1 = 0.0, r2 = 0.0, vin = 0.0, vout = 0.0; // Step 5, problem 5: Finds the voltage out from given inputs
	printf("Enter the resistance 1, resistance 2, and voltage in(All float point values) for use in finding the Voltage out: ");
	scanf("%lf%lf%lf", &r1, &r2, &vin); // Scans in values from the user
	vout = r2 / ((r1 + r2)*vin); // calculates the vout from the given equation 
	printf("Voltage out = r2 / (r1+r2)*vin = %lf / (%lf +%lf) * %lf = %lf\n\n", r2, r1, r2, vin, vout);

	double x1 = 0.0, y1 = 0.0, x2 = 0.0, y2 = 0.0, cords1 = 0.0, cords2 = 0.0, cordsfinal = 0.0; //Step 6, problem 6: Finds the distance between two points
	printf("Enter the first point x1,y1, and the second point x2, y2 for use in the distance formula: ");
	scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2); // Scans in the values for the first and second points from the user.
	cords1 = (x1 - x2) * (x1 - x2);	// Takes the value of x1 - x2 and squares it
	cords2 = (y1 - y2) * (y1 - y2); // squares the value of y1 - y2
	cordsfinal = cords1 + cords2; // Takes the squared x1-x2 values and the squared y1-y2 values and adds them together
	cordsfinal = sqrt(cordsfinal);	// Takes the square root from the previous value giving us the distance between two points
	printf("Distance between two points of (%lf, %lf) and (%lf, %lf) = %lf\n\n", x1, y1, x2, y2, cordsfinal);

	double z = 0.0, x = 0.0, genfinal = 0.0; // Step 7, problem 7: Uses values from the user to calculate a general formula
	int a = 0; // If a is an even integer the equation won't work the intended way
	printf("Enter values for z, x, (both float values) and a(odd integer value) for use in the general equation: ");
	scanf("%lf%lf%d", &z, &x, &a); // scans in double values for z and x, while an integer value for a 
	genfinal = (double)89 / 27 - z * x + a / (a % 2); // General equation given from PA1 instructions
	printf("General Equation = (89/27) - z * x + a / (a % 2) = (89/27) - %lf * %lf + %d / (%d %% 2) = %lf\n\n", z, x, a, a, genfinal);

	system("pause");	//Allows the screen to stay up
	return 0;
}