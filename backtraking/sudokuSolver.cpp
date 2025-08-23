#include <iostream>
using namespace std;

bool isValid(vector<vector<char>> &board, int row, int col, char ch)
{
    for (int i = 1; i < 9; i++)
    {
        if (board[row][i] == ch)
        {
            return false;
        }

        if (board[i][col] == ch)
        {
            return false;
        }

        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == ch)
        {
            return false;
        }
    }

    return true;
}

bool solve(vector<vector<char>> &board)
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            if (board[i][j] == '.')
            {
                for (char ch = '1'; ch <= '9'; ch++)
                {
                    if (isValid(board, i, j, ch))
                    {
                        board[i][j] = ch;

                        if (solve(board) == true)
                        {
                            return true;
                        }
                        else
                        {
                            board[i][j] = '.';
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}

bool toSolve(vector<vector<char>> &board, int row, int col)
{
    if (row == 9)
    {
        return true;
    }

    if (col == 9)
    {
        return toSolve(board, row + 1, 0);
    }
    if (board[row][col] != '.')
    {
        return toSolve(board, row, col + 1);
    }

    for (char digit = '1'; digit <= '9'; digit++)
    {
        if (isValid(board, row, col, digit))
        {
            board[row][col] = digit;

            if (toSolve(board, row, col + 1))
            {
                return true;
            }
            board[row][col] = '.';
        }
    }
    return false;
}

int main()
{
    vector<vector<char>> board = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                                  {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                                  {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                                  {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                                  {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                                  {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                                  {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                                  {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                                  {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    toSolve(board, 0, 0);

    for (auto nums : board)
    {
        cout << "[";
        for (auto num : nums)
        {
            cout << "'" << num << "'" << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}