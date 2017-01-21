Jonathan Gaines


This program takes a user-provided year and returns the corresponding calendar.
To run this program, you must navigate to the root directory of the program and
type "./PA1" into the terminal. At this point, the program will be executed.
During the development of this program, the biggest issue I encountered was the
implementation of scanf() which was entirely resulting from a lack of understanding.
I now understand it after working through these issues. 

The algorithm I used to determine which day of the week a given day was on was
borrowed from a third party (the link to the source is given below). This
algorithm is as defined and returns a value ranging from 0-6 (0=Saturday,
1=Sunday, ..., 6=Friday):
N = (day + 2*month + 3*(month+1)/5 + year + year/4 - year/100 + year/400 + 2) %
7

This algorithm is capable of calculating the day of week for any given day, month, and year values and takes into account leap years. One thing to keep in mind with this algorithm is that the months of January and Febuary must be passed into it as months #13 and #14 of the previous year. For example:
1. January 1st, 2010 --> day=1, month=13, year=2009
2. Febuary 15th, 2020 --> day=15, month=14, year=2019
With this in mind, the month of March is still month #3 and all the other months have their respective numerical values. 
		
Source of Algorithm:
http://mathforum.org/library/drmath/view/55837.html

Loop Invariants:

1) Iterates until the value of the variable, i, is no longer more than one less than the passed starting day. This is for the purpose of starting the first day of the month in the correct location under it's corresponding day of the week. Additionally, the variable, space, increments by one each iteration.

2) Iterates until the variable, d, is equal to the variable, val, which is passed into this function as the number of days in the month. This loop also increments the space variable by one and if it's value is a multiple of 7 (meaning it is the last space of the line) it will create a new line.

3) Cycles through every month of the year and calls printMonth(), passing the month variable into that function. Each time the loop iterates, the month variable is increased by 1 until it is equal to 12 (corresponding to the months of the year).

4) Tests to see if the input year is a positive number, while it is not, it asks for a new year to be input. This loop keeps running until the year is positive.





