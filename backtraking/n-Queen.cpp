#include <iostream>
using namespace std;
bool safe(int col, int row, vector<string> &board, int n)
{
    int duplicateRow = row;
    int duplicateCol = col;

    // upper left diagonal
    while (row >= 0 && col >= 0)
    {
        if (board[row][col] == 'Q')
        {
            return false;
        }
        row--;
        col--;
    }

    // same row and left cols
    row = duplicateRow;
    col = duplicateCol;
    while (col >= 0)
    {
        if (board[row][col] == 'Q')
        {
            return false;
        }
        col--;
    }

    // lower left diagonal
    row = duplicateRow;
    col = duplicateCol;
    while (col >= 0 && row < n)
    {
        if (board[row][col] == 'Q')
        {
            return false;
        }
        col--;
        row++;
    }

    return true;
}
void fun(int col, vector<vector<string>> &ans, vector<string> &board, int n)
{
    if (col == n)
    {
        ans.push_back(board);
    }

    for (int row = 0; row < n; row++)
    {
        if (safe(col, row, board, n))
        {
            board[row][col] = 'Q';
            fun(col + 1, ans, board, n);
            board[row][col] = '.';
        }
    }
}

int main()
{
    int n = 4;
    vector<vector<string>> ans;
    vector<string> board(n,string(n, '.'));

    fun(0, ans, board, n);

    for (auto an : ans)
    {
        cout << "{";
        for (auto val : an)
        {
            cout << "[" << val << "]" << " ";
        }
        cout<<"}"<<endl;
    }
    return 0;
}