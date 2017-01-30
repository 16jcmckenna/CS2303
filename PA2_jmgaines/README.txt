Author: Jonathan Gaines
1/30/17

Project Summary: 
		John Conway's Game of Life is a mathematical game which models the idea of 
	cellular automation. Based on several mathematical conditions, an organism 
	either lives, dies, or births. From these different conditions, many unique
	patterns emerge. 

------------------------------------------------------------------------------
To run:
		In your terminal, navigate to the root directory of the program and type
	without <>:
	"./life <x value> <y value> <number of generations> <input file name> <'y' or 
	'n' for printing generations> <'y' or 'n' for pausing between generations>"

	The last two arguements are optional. Here are a few examples:
		EX 1: ./life 50 50 1000 input.txt y y
		EX 2: ./life 10 40 400 input.txt
	 	EX 3: ./life 70 21 5000 input.txt y n
		EX 4: ./life 90 13 4000 input.txt n

------------------------------------------------------------------------------
Problems During Development:
		During the development, the biggest problem I encountered was relating to
	allocation of memory for the 2D arrays. Once I figured out how to allocate
	memory for one 2D array, I wanted to convert that to a function which I could 
	recall for my other arrays. Once I understood the logic behind pointers, the
	development of this function was trivial.	

------------------------------------------------------------------------------
Loop Invariants:
1.y contains length of matrix, i increments while it is less than y  
	memory allocated for y length and i is 1 less than y

2.i and j will increment until i is one less than y and j is one less than x
	i and j are one less than y and x; all matrix positions have been cycled over

3.i equals zero and will loop twice
	i equals 2 now and will therefore no longer cycle

4.read equals the current line, and the loop will cycle while it hasn't 
reached the last line in the file
	read equals -1 and exits the while loop

5.x_assign equals the starting value of x which was assigned the first time 
through the parent for loop and will increment until the line_length of the 
given line is reached
	x_assign has reached the line_length[] array value

6.i and j will increment until i is one less than y and j is one less than x
	i and j are one less than y and x; all matrix positions have been cycled over

7.i and j will increment until i is one less than y and j is one less than x
	i and j are one less than y and x; all matrix positions have been cycled over

8.i and j will increment until i is one less than y and j is one less than x
	i and j are one less than y and x; all matrix positions have been cycled over

9.i and j will increment until i is one less than y and j is one less than x
	i and j are one less than y and x; all matrix positions have been cycled over

10.i and j will increment until i is one less than y and j is one less than x
	 i and j are one less than y and x; all matrix positions have been cycled over

11.i and j will increment until i is one less than y and j is one less than x
	 i and j are one less than y and x; all matrix positions have been cycled over

12.i and j will increment until i is one less than y and j is one less than x
	 i and j are one less than y and x; all matrix positions have been cycled over

13.Cycles until the function is_complete returns a value of 1
	 Game of life is complete

	 
