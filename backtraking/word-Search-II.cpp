#include <iostream>
using namespace std;

// Brute Force approch
bool funBrute(vector<vector<char>> &board, string &word, int row, int col, int index)
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

    bool found = (funBrute(board, word, row, col + 1, index + 1) ||
                  funBrute(board, word, row, col - 1, index + 1) ||
                  funBrute(board, word, row - 1, col, index + 1) ||
                  funBrute(board, word, row + 1, col, index + 1));

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
            if (funBrute(board, word, i, j, 0))
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

// Better Force approch
bool funBetter(vector<vector<char>> &board, string &word, int row, int col, int index)
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

    bool found = (funBetter(board, word, row, col + 1, index + 1) ||
                  funBetter(board, word, row, col - 1, index + 1) ||
                  funBetter(board, word, row - 1, col, index + 1) ||
                  funBetter(board, word, row + 1, col, index + 1));

    board[row][col] = temp;
    return found;
}
void existBetter(vector<vector<char>> &board, vector<string> &words)
{
    vector<string> result;
    for (int k = 0; k < words.size(); k++)
    {
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (funBetter(board, words[k], i, j, 0))
                {
                    result.push_back(words[k]);
                    break;
                }
            }
        }
    }

    for (auto word : result)
    {
        cout << word << " ";
    }
}

int main()
{
    vector<vector<char>> board = {{'o', 'a', 'a', 'n'},
                                  {'e', 't', 'a', 'e'},
                                  {'i', 'h', 'k', 'r'},
                                  {'i', 'f', 'l', 'v'}};
    vector<string> words = {"oath", "pea", "eat", "rain"};

    // Brute Force approch
    // for (int i = 0; i < word.size(); i++)
    // {
    //     if(exist(board, word[i])){
    //         cout<<word[i]<<" ";
    //     }
    // }
    // cout<<endl;

    // Better Force approch
    existBetter(board, words);
    return 0;
}