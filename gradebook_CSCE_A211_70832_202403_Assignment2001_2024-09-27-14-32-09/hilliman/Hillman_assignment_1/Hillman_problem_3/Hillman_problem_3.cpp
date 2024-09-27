

#include <iostream>

int main()
{
    std::cout << "Hello World!\n";
}

// # 1   Maze Search Algorithm
//
// Move forward
// If collision detected, rotate left 90 degrees
// Move forward
// If collision detected, rotate right 180 degrees, else return to step 1
// repeat until exit detected


// The algorithm above will avoid going in circles and explore all paths in the maze until it eventually finds the exit.
// However, the described approach is inefficient as it does not track previously visisted locations.



// # 2 Maze generation

// A good maze will always have a path from any empty space inside all the way to the exit. It also should use it's total
// space efficiently, always providing paths instead of large sections of completely filled space.


// Maze Generation Algorithm
//
// Create filled x by y rectangle/square
// Pick one the four corners randomly
//      From a position one row and column inside that corner
//      Draw semi-random path to exit
//      repeat for each corner
// Detect largest area of filled space
//      Draw semi-random path that connects to another path
//      repeat until largest area of filled space is below some threshold

