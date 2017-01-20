/*
 * PA1.c
 *
 * 	Created on: Jan 14, 2017
 *      Author: Jonathan Gaines
 */

#include <stdio.h>

int inputYear;

int leapYear(int y) {

	//determines if a year is a leap year
	if((y % 4 == 0) && (y % 100 != 0 || y % 400 == 0)){
		return 1;
	}
	return 0;
}

int getStartingDay (int d, int m, int y) {

	//converts January and February to months of previous years as needed for algorithm
	if(m == 1){
		m = 13;
		y--;
	}
	else if(m == 2){
		m = 14;
		y--;
	}

	//returns value between 0 and 6 corresponding to the day of the week
	//0 = saturday .. 6 = friday
	return (d + 2*m + 3*(m+1)/5 + y + y/4 - y/100 + y/400 + 2) % 7;
}

void printDays(int val, int start_day) {
	printf("Sun  Mon  Tue  Wed  Thu  Fri  Sat \n");
	int space = 0;
	if(start_day == 0) {
		start_day = 7;
		space = 7;
	}
	for(int i = 0; i < start_day-1; i++) {
		printf("     ");
		space++;
	}
	for(int d = 1; d <= val; d++){
		printf("%3i  ", d);
		space++;
		if(space%7 == 0){ //if space reached is the 7th of the row, go to new line
			printf("\n");
		}
	}
	printf("\n");
}

void printMonthName (int y, int m, int start_day) {
	printf("\n\n");
	switch(m) {
	case 1:
		printf("January %i\n\n", y);
		printDays(31, start_day);
		break;
	case 2:
		printf("February %i\n\n", y);
		if(leapYear(y))
			printDays(29, start_day);
		else
			printDays(28, start_day);
		break;
	case 3:
		printf("March %i\n\n", y);
		printDays(31, start_day);;
		break;
	case 4:
		printf("April %i\n\n", y);
		printDays(30, start_day);
		break;
	case 5:
		printf("May %i\n\n", y);
		printDays(31, start_day);
		break;
	case 6:
		printf("June %i\n\n", y);
		printDays(30, start_day);
		break;
	case 7:
		printf("July %i\n\n", y);
		printDays(31, start_day);
		break;
	case 8:
		printf("August %i\n\n", y);
		printDays(31, start_day);
		break;
	case 9:
		printf("September %i\n\n", y);
		printDays(30, start_day);
		break;
	case 10:
		printf("October %i\n\n", y);
		printDays(31, start_day);
		break;
	case 11:
		printf("November %i\n\n", y);
		printDays(30, start_day);
		break;
	case 12:
		printf("December %i\n\n", y);
		printDays(31, start_day);
		break;
	}
}

void printMonth(int y, int m, int start_day) {
	printMonthName(y, m, start_day);
}

void printCalender(int year, int day) {
	printf("\n\n  ***\tCALENDAR FOR %i   ***", year);
	// goes through every month of the year and calls printMonth(), passing the month variable into that function
	for(int month = 1; month <= 12; month++) {
		printMonth(year, month, getStartingDay(1, month, year));
	}
}

int main (void) {
	printf("Enter year for it's calendar: ");
	scanf("%i", &inputYear);

	printCalender(inputYear, getStartingDay(1,1,inputYear));

	return 0;
}


