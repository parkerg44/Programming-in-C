/* Author: Parker Guillen
1/30/17
Description: PA 2, Asks the user for many different values to be used in various equations through the use of functions.
Collaborators: Professor's Fallons code from class for encoding character*/
#include "equations.h"

int main(void)
{	
	// Force Equation
	double mass = 0.0, accel = 0.0, force1 = 0.0;	//Step 1: Defines needed variables, takes inputs from the user for the force equation, calls the function.
	printf("Enter the mass and acceleration (Both float point values) for use in Newton's second law:\n ");
	scanf("%lf%lf", &mass, &accel);
	force1 = calculate_newtons_2nd_law(mass, accel);
	printf("Newton's Second Law: Force = Mass * Accelertion = %.2lf * %.2lf = %.2lf\n\n ", mass, accel, force1);

	// Volume of a Cylinder
	double radius = 0.0, height = 0.0, volume1 = 0.0;	//Step 2: Defines needed variables, takes input from user for use in calculating volume, calles function for volune.
	printf("Enter the radius and height (Both float point values) for use to find the volume of a cylinder:\n ");	
	scanf("%lf%lf", &radius, &height);
	volume1 = calculate_volume_cylinder(radius, height);
	printf("Volume of a cylinder = PI * radius^2 * height = %.2lf * %.2lf^2 * %.2lf = %.2lf\n\n", PI, radius, height, volume1);

	// Character Encoding
	char character = 'a', plaintext = '\0', encodechr1 = '\0'; //Step 3: Defines a char, takes values from the user, calls the character encoding function, prints the result.
	printf("Enter a plaintext character: ");	
	scanf(" %c", &plaintext);
	encodechr1 = perform_character_encoding(plaintext);
	printf("Encoded Character: %c\n\n", encodechr1);

	// Force of Gravity
	double mass1 = 0.0, mass2 = 0.0, distance = 0.0, gforce1 = 0.0; //Step 4: Defines the double variables, for use in finding the gravitational force, calls function for gforce
	printf("Enter the first mass, second mass, and the distance (All float point values) for use in finding force:\n");
	scanf("%lf%lf%lf", &mass1, &mass2, &distance);
	gforce1 = calculate_gravity_force(mass1,mass2,distance);
	printf("Force = G * mass1 * mass2 / distance^2 = %.2e * %.2lf * %.2lf / %.2lf^2 = %.2e\n\n", G, mass1, mass2, distance, gforce1);

	// Voltage Equation
	double r1 = 0.0, r2 = 0.0, vin = 0.0, vout1 = 0.0; //Step 5: Defines required input values, scans in values and calls function to calculate voltage out
	printf("Enter the resistance 1, resistance 2, and voltage in(All float point values) for use in finding the Voltage out: ");
	scanf("%lf%lf%lf", &r1, &r2, &vin);
	vout1 = calculate_resistive_divider(r1,r2, vin);
	printf("Voltage out = r2 / (r1+r2)*vin = %.2lf / (%.2lf + %.2lf) * %.2lf = %.2e\n\n", r2, r1, r2, vin, vout1);

	// Distance formula 
	double x1 = 0.0, y1 = 0.0, x2 = 0.0, y2 = 0.0, cordsfinal1 = 0.0; //Step 6: Defines the variables as doubles and scans them in, calls the function to calculate distance
	printf("Enter the first point x1,y1, and the second point x2, y2 for use in the distance formula: ");
	scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
	cordsfinal1 = calculate_distance_between_2pts(x1, x2, y1, y2);
	printf("Distance between two points of (%.2lf, %.2lf) and (%.2lf, %.2lf) = %.2lf\n\n", x1, y1, x2, y2, cordsfinal1);

	// General Equation
	double z = 0.0, x = 0.0, genfinal1 = 0.0; //Step 7: defines int and double variables, calls the general equation function.
	int a = 0; 
	printf("Enter values for z, x, (both float values) and a(odd integer value) for use in the general equation: ");
	scanf("%lf%lf%d", &z, &x, &a);
	genfinal1 = calculate_general_equation(a, x, z);
	printf("General Equation = (89/27) - z * x + a / (a % 2) = (89/27) - %.2lf * %.2lf + %d / (%d %% 2) = %.2lf\n\n", z, x, a, a, genfinal1);

	system("pause");
	return 0;
}