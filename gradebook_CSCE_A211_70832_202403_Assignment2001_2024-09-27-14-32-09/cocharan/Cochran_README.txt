
Benford's Law:
_________________________________________________________________________________________________________
|													|
|													|
|		The benford_law.cpp program takes in exactly 3295 integers from input and counts	| 
|	the amount for each digit 1 to 9 used as the first digit for each integer before displaying	|
|	those counts to the user.									|
|													|
|		The program is best used when inputting a text document filled with just integers	|
|	into the program using the Linux command "<". below is an example of usage in the command line 	|
|	with the output (directory not shown): 								| 
|_______________________________________________________________________________________________________|
|													|
|	g++ benford_law.cpp										|
|	./a.out < enrollments.txt									|
|													|
|	The amount of numbers that started with:							|
|	#1: 1295											|
|	#2: 789												|
|	#3: 314												|
|	#4: 230												|
|	#5: 152												|
|	#6: 118												|
|	#7: 129												|
|	#8: 164												|
|	#9: 104												|
|													|
|_______________________________________________________________________________________________________|



Chuck-a-luck:
_________________________________________________________________________________________________________
|													|
|													|
|		The Chuck-a-luck.cpp program gives the user an amount in their account, $100, and then  |
|	prompts the user for a wager. If the wager is above the amount in the account or below 0, then  |
|	the user is told to only enter values on the range and is then repromoted for input.		|
|		When the user enters a valid wager that is between 0 and the account balance, they will |
|	be echoed back their wager before being prompted for their betting number. 			|
|		When the user is prompted for their betting number, they will be asked to input a number|
|	from 1 to 6. The program will check the number the user inputs to make sure it is a number on	|
|	that range before continuing, otherwise the user will be repromoted. 				|
|		After receiving the user's betting number, the program will echo back the number then	|
|	generate 3 random numbers from 1 to 6. If any of the numbers match the user's number, the user's|
|	account gains the amount of those three random numbers that equal the user's betting number	|
|	times the wager.										|
|		If none of the three random numbers equal the user's betting number, the user's account	|
|	losses the amount of that wager.								|
|		If at this time the user's account is equal to zero, the program tells the user that	|
|	their account is out of cash and that they have reached a game over before terminating the	|
|	program.											|
|		Otherwise, if the user's account is not equal to zero, then the user is prompted for if |
|	they wish to play another round, that is, for a yes or no (y, Y, n, or N).			|
|		The program is built so that the responses such as "yes", "Yes", "y", "Y", "yup", ect.	|
|	are treated the same (same with "no", "No", "n", "No", "nope", ect.).				|
|		When the user enters a yes response, "y" for example, the program loops back to entering|
|	 a wager.											|
|		When the user enters a no response, "n" for example, the program proceeds to terminate.	|
|	 												|
|		Below are the commands to get the code to run in a unix system:				|
|	 _______________________									|
|	|g++ Chuck-a-luck.cpp	|									|
|	|./a.out		|									|
|	|_______________________|									|
|													|
|		An example usage of this code:								|
|	 												|
|_______________________________________________________________________________________________________|
|													|
|	Your account: $100										|
|	What is your wager?										|
|	Enter your wager: 20								 		|
|													|
|	You wagered: $20										|
|													|
|	What is your betting number?									|
|	Enter a whole number from 1 to 6: 4								|
|													|
|	Your betting number:4										|
|													|
|	rolling the dice...										|
|													|
|	You rolled your number 1 times!									|
|	You won $20!											|
|													|
|	Your account: $120										|
|													|
|	Do you wish to play another round?								|
| 	Enter 'y' or 'n': n										|
|													|
|	Thanks for playing!										|
|													|
|_______________________________________________________________________________________________________|



Maze Generation and Maze Solving:
_________________________________________________________________________________________________________
|													|
|	Part 1:												|
|		The algorithm that would be able to solve the maze and any randomly generated one, would|
|	start by finding the angle between it's forward direction, set default to north (that being up),| 
|	and a line drawn from it to the exit. It will then proceed to check the spaces in it's forward, |
|	left, and right directions for if they are spaces it can move to. 				|
|		If none can be moved to, then rotate the direction by 180 degrees and continue by moving|
|	in that direction before looping back to finding the angle between it's forward direction and a |
|	line from it to the exit.									|
|		If there is a space it can move to, it will select the space in the direction with the  |
|	smallest degree in difference to the line going from the algorithm's position the exit and set  |
|	the rotation to that direction before moving that way.						|
|		The algorithm will end once it has reached the exit.					|
|													|
|	Part 2:												|
|		A good maze would be one that does not have any explicit solution nor pattern. It should|
|	branch out but not too little nor too much (i.e. not one long spaghetti noodle of a maze nor one|
|	that )
|		One way an AI program could generate a maze is via a branching method where the program |
|	will create a path that branches out into multiple paths. 					|
|		The program will start from the exit, paving a path that will decide randomly, with 	|
|	weights, the direction to move in after the first move inward. After a set minimum distance, the| 
|	program will randomly decide in 1 to 3 spaces to create a new branch of the maze. 		|
|		This branch will run the same as main, or the branch before it, creating branches of	|
|	it's own as it goes. If a branch cannot be created. i.e. If the is only one space open to create|
|	path, the program will delay branching until two or more empty spaces are available.		|
|		If the main branch or any other branch finds it has no empty spaces left to move, that  |
|	branch will terminate, removing itself from the list of active branches and no longer paving new|
|	paths.												|
|		When all paths have terminated, the program will run through the maze, line-by-line or  |
|	column-by-column (chosen randomly) in a random direction to find any empty spots where no path  |
|	has been created. When this happens, the program will create a new branch starting at that 	|
|	location, connected to one of the nearby paths (in the case that there is no nearby paths, the  |
|	program will find an empty space next to a path to start at instead). The program will repeat 	|
|	this process until it competes a run without finding any empty spaces in the maze.		|
|													|
|_______________________________________________________________________________________________________|



Reference Parameters:
_________________________________________________________________________________________________________
|													|
|		The Reference Parameters program starts by giving the user two examples of cents being  |
|	converted to change. Then, it asks the user 
|
|
|													|
|_______________________________________________________________________________________________________|
|													|
|	Converting 269 cents into change:
|	quarters: 10
|	dimes:    1
|	nickels:  1
|	pennies:  4
|	
|	Converting 9999 cents into change:
|	quarters: 399
|	dimes:    2
|	nickels:  0
|	pennies:  4
|
|	Enter the amounr in cents to convert to change:
|	Enter a whole number from 1 to 99:
|	69
|
|
|	Converting 9999 cents into change:
|	quarters: 2
|	dimes:    1
|	nickels:  1
|	pennies:  4

|													|
|_______________________________________________________________________________________________________|