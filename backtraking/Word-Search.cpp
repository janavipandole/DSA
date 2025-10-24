#include <iostream>
using namespace std;

bool fun(vector<vector<char>> &board, string &word, int row, int col, int index)
{
    if (index == word.size())
    {
        return true;
    }
    if (row < 0 || col < 0 || row >= board.size() || col >= board[0].size() || board[row][col] != word[index])
    {
        return false;
    }
    char temp = board[row][col];
    board[row][col] = '#';

    bool found = (fun(board, word, row, col + 1, index + 1) ||
                  fun(board, word, row, col - 1, index + 1) ||
                  fun(board, word, row - 1, col, index + 1) ||
                  fun(board, word, row + 1, col, index + 1));

    board[row][col] = temp;
    return found;
}
bool exist(vector<vector<char>> &board, string &word)
{
    bool result = false;
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            if (fun(board, word, i, j, 0))
            {
                result = true;
                break;
            }
        }
        if (result)
        {
            break;
        }
    }
    return result;
}
int main()
{
    vector<vector<char>> board = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    string word = "ABCB";
    cout << exist(board, word) << endl;
    return 0;
}