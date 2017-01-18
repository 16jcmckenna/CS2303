/* Jonathan Gaines */

#include <stdio.h>
#include <math.h>

double x1;
double y1;
double x2;
double y2;
double x3;
double y3;

double length(double x1, double x2, double y1, double y2) {
	return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

double circumference(double ab, double bc, double ca) {
	return ab + bc + ca;
}

double area(double ab, double bc, double ca) {
	double s = circumference(ab, bc, ca) / 2;
	return sqrt(s * (s - ab) * (s - bc) * (s - ca));
}

int main(void) {
	printf("Enter the x- and y-coordinates of point A: ");
	scanf("%d %d", &x1, &y1);
	printf("Enter the x- and y-coordinates of point B: ");
	scanf("%d %d", &x2, &y2);
	printf("Enter the x- and y-coordinates of point C: ");
	scanf("%d %d", &x3, &y3);

	double ab = length(x1, x2, y1, y2);
	double bc = length(x2, x3, y2, y3);
	double ca = length(x3, x1, y3, y1);


	printf("Length of AB %d \n", ab);
	printf("Length of BC %d \n", bc);
	printf("Length of CA %d \n", ca);
	printf("Circumference is %d \n", circumference(ab, bc, ca));
	printf("Area is %d \n", area(ab, bc, ca));
	return 0;
}
