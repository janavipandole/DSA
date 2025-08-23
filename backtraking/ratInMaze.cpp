#include <iostream>
using namespace std;

void toGetAllPathsBruteForce(vector<string> &allPossiblePaths, string path, vector<vector<int>> &maze, int row, int col, vector<vector<bool>> &visited)
{
    if (row == maze.size() - 1 && col == maze[0].size() - 1)
    {
        allPossiblePaths.push_back(path);
        return;
    }
    if (row < 0 || col < 0 || row >= maze.size() || col >= maze[0].size() || maze[row][col] != 1 || visited[row][col] != false)
    {
        return;
    }

    visited[row][col] = true;

    // Down
    toGetAllPathsBruteForce(allPossiblePaths, path + 'D', maze, row + 1, col, visited);
    // Left
    toGetAllPathsBruteForce(allPossiblePaths, path + 'L', maze, row, col - 1, visited);
    // Right
    toGetAllPathsBruteForce(allPossiblePaths, path + 'R', maze, row, col + 1, visited);
    // Up
    toGetAllPathsBruteForce(allPossiblePaths, path + 'U', maze, row - 1, col, visited);

    visited[row][col] = false;
}

void toGetAllPathsOptimal(vector<string> &allPossiblePaths, string path, vector<vector<int>> &maze, int row, int col)
{
    if (row == maze.size() - 1 && col == maze[0].size() - 1)
    {
        allPossiblePaths.push_back(path);
        return;
    }
    if (row < 0 || col < 0 || row >= maze.size() || col >= maze[0].size() || maze[row][col] != 1)
    {
        return;
    }

    maze[row][col] = -1;

    // Down
    toGetAllPathsOptimal(allPossiblePaths, path + 'D', maze, row + 1, col);
    // Left
    toGetAllPathsOptimal(allPossiblePaths, path + 'L', maze, row, col - 1);
    // Right
    toGetAllPathsOptimal(allPossiblePaths, path + 'R', maze, row, col + 1);
    // Up
    toGetAllPathsOptimal(allPossiblePaths, path + 'U', maze, row - 1, col);

    maze[row][col] = 1;
}

int main()
{
    vector<vector<int>> maze{{1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1}};
    vector<vector<bool>> visited(maze.size(), vector<bool>(maze[0].size(), false));
    vector<string> allPossiblePaths;
    string path;

    toGetAllPathsBruteForce(allPossiblePaths, path, maze, 0, 0, visited);

    for (auto str : allPossiblePaths)
    {
        cout << str << " ";
    }
    cout << endl;
    return 0;
}