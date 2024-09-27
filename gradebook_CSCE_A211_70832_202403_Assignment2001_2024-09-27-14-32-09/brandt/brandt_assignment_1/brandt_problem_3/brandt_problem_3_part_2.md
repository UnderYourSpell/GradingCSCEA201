Q: Think of a way to have a computer generate a random maze. What are
   important criteria that a good maze should have? Describe how your
   algorithm could possibly meet the criteria.

## Important Criteria
A maze must have an exit that can be reached from any point in the maze
A maze should only have one exit and one entrance
A maze should not have more than one path to the exit


## My Maze Generation Algorithm
1. Place the entrance
	Decide on the length and width of maze (must be a multiple of 3)
	Pick a side to be the entrance side, the opposite will be the exit side
	Pick a random point on the entrance side to place the entrance

2. Determine the main path
	Each maze generating movement determines a 3x3 sqaure of the maze
	Randomly walk in the 4 cardinal directions, making sure you don't cross any of previously tread path, until you hit the exit wall
	Place the exit at that point
	ex of path 3x3:
	# #
	# 
	# #

3. Determine dead end paths
	Pick a random point on the main path to do a random walk
	Do a random walk until you hit another part of a path
	Have a small chance to branch out into another random walk
	Place a path 3x3 on each movement
	Place a dead end
	ex of dead end 3x3:
	###
	# #
	# #
	Continue creating dead end paths until you are satisfied (you could set the program to create 5 or 10 dead end paths at random points in the main path)
