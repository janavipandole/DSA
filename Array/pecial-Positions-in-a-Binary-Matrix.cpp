#include <iostream>
using namespace std;
class Solution
{
public:
    bool rowZero(int i, vector<vector<int>> &mat, int m, int col)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == 1 && col != j) return false;
        }
        return true;
    }
    bool colZero(int j, vector<vector<int>> &mat, int n, int row)
    {
        for (int i = 0; i < n; i++)
        {
            if (mat[i][j] == 1 && row != i)return false;
        }
        return true;
    }
    int numSpecial(vector<vector<int>> &mat)
    {
        int count = 0;
        int n = mat.size();
        int m = mat[0].size();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] == 1)
                {
                    if (rowZero(i, mat, m, j) == true && colZero(j, mat, n, i))
                    {
                        count++;
                    }
                }
            }
        }
        return count;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> mat = {{1, 0, 0}, {0, 0, 1}, {1, 0, 0}};
    cout << "Special Positions in a Binary Matrix : " << s.numSpecial(mat) << endl;
    return 0;
}