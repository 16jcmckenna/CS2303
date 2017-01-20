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

	/* 1. Iterates until the value of the variable, i, is no longer more than one less than
	the passed starting day. This is for the purpose of starting the first day of the 
	month in the correct location under it's corresponding day of the week. Additionally,
	the variable, space, increments by one each iteration. */
	for(int i = 0; i < start_day-1; i++) {
		printf("     ");
		space++;
	}

	/* 2. Iterates until the variable, d, is equal to the variable, val, which is passed into
	this function as the number of days in the month. This loop also increments the space
	variable by one and if it's value is a multiple of 7 (meaning it is the last space of 
	the line) it will create a new line. */
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


	/* 3. Cycles through every month of the year and calls printMonth(),
	passing the month variable into that function. Each time the 
	loop iterates, the month variable is increased by 1 until it is
	equal to 12 (corresponding to the months of the year).*/
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


