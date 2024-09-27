
Q: Given a random start location, think of an algorithm that does not use recursion
   that would find its way to the exit S. Your algoritm should be able to run on an
   arbitrary maze, and not be specific to the sample given above. Can your algorithm
   avoid going in circles? Describe your algorithm.


## Assumptions
I am going to assume a few things
	- I do not start in a wall
	- There is a possible path that will lead to the exit

## Variables / Information Storage
I am going to store each fork in the path on a stack
A fork in the path is anywhere the program has to choose between two possible decisions
Each way that has been explored is stored into the current fork

I am also storing my last position

## Functions
**Move Function**
	Move to designated square
	Can only ever move one sqaure

**Check Position Data Function:**
	Check cardinal directions for walls
	You cannot move to your last position
	If there are still multiple valid moves then it is a fork (Deal With Fork)
	If there is a dead end then check top fork for any valid positions
		- If there are no more valid positions in the fork then pop off that fork and check next fork
		- Continue checking forks on the stack until you find a fork with valid positions then (Deal With Fork)
	If you are at the end exit the function
	Otherwise (Move) to next sqaure

**Deal With Fork Function:**
	If current position is not top fork add current position onto fork stack
	Move into random open sqaure
	Store way you moved onto top fork in the stack



## Solution
Keep running Check Position Data until exit is found and exit the program
