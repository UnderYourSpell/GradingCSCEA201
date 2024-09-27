#include <iostream>
#include <queue>
using namespace std;

// Define the maze size
const int ROWS = 5;
const int COLS = 5;

// Directions for moving up, down, left, and right
int rowDir[] = { -1, 1, 0, 0 };
int colDir[] = { 0, 0, -1, 1 };

int main() {
    // Sample maze: 'X' is a wall, ' ' is a path, 'S' is the exit
    char maze[ROWS][COLS] = {
        {' ', 'X', 'X', 'X', 'X'},
        {' ', ' ', 'X', ' ', 'X'},
        {'X', ' ', 'X', ' ', 'X'},
        {'X', ' ', ' ', ' ', 'S'},
        {'X', 'X', 'X', 'X', 'X'}
    };

    bool visited[ROWS][COLS] = { false };  // Track visited cells
    queue<pair<int, int>> q;

    int startRow = 0, startCol = 0;  // Start position
    q.push({ startRow, startCol });
    visited[startRow][startCol] = true;

    while (!q.empty()) {
        auto [row, col] = q.front();
        q.pop();

        if (maze[row][col] == 'S') {
            cout << "Exit found at (" << row << ", " << col << ")!" << endl;
            return 0;
        }

        // Explore all four directions
        for (int i = 0; i < 4; i++) {
            int newRow = row + rowDir[i];
            int newCol = col + colDir[i];

            // Check bounds and if the cell is valid (not a wall or already visited)
            if (newRow >= 0 && newRow < ROWS && newCol >= 0 && newCol < COLS
                && maze[newRow][newCol] != 'X' && !visited[newRow][newCol]) {
                q.push({ newRow, newCol });
                visited[newRow][newCol] = true;
            }
        }
    }

    cout << "No exit found!" << endl;
    return 0;
}
