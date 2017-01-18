/* Jonathan Gaines */

#include <stdio.h>
#include <math.h>


double length(double xa, double xb, double ya, double yb) {
	return sqrt(pow((xa-xb), 2) + pow((ya-yb), 2));
}

double circumference(double ab, double bc, double ca) {
	return ab + bc + ca;
}

double area(double ab, double bc, double ca) {
	double s = circumference(ab, bc, ca) / 2;
	return sqrt(s * (s - ab) * (s - bc) * (s - ca));
}

int main(void) {
	double xa, ya, xb, yb, xc, yc;

	printf("Enter the x- and y-coordinates of point A: ");
	scanf("%lf %lf", &xa, &ya);
	printf("Enter the x- and y-coordinates of point B: ");
	scanf("%lf %lf", &xb, &yb);
	printf("Enter the x- and y-coordinates of point C: ");
	scanf("%lf %lf", &xc, &yc);

	double ab = length(xa, xb, ya, yb);
	double bc = length(xb, xc, yb, yc);
	double ca = length(xc, xa, yc, ya);


	printf("Length of AB %lf \n", ab);
	printf("Length of BC %lf \n", bc);
	printf("Length of CA %lf \n", ca);
	printf("Circumference is %lf \n", circumference(ab, bc, ca));
	printf("Area is %lf \n", area(ab, bc, ca));
	return 0;
}
