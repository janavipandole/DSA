#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int celebrityBrute(vector<vector<int>> &matrix)
    {
        int n = matrix.size();

        vector<int> knowMe(n, 0);
        vector<int> iKnow(n, 0);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == 1 && i != j)
                {
                    iKnow[i] += 1;
                    knowMe[j] += 1;
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (knowMe[i] == n - 1 && iKnow[i] == 0)
            {
                return i;
            }
        }
        return -1;
    }

    int celebrityOptimal(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int top = 0;
        int down = n - 1;

        while (top < down)
        {
            if (matrix[top][down] == 1)
            {
                top++;
            }
            else if (matrix[down][top] == 1)
            {
                down--;
            }
            else
            {
                top++;
                down--;
            }
        }
        if (top > down) return -1;

        for (int j = 0; j < n; j++)
        {
            if ((matrix[top][j] == 1 || matrix[j][top] == 0) && (j != top)) return -1;
        }
        return top;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> matrix = {{0, 1, 0, 0},
                                  {0, 0, 0, 0},
                                  {0, 1, 0, 0},
                                  {1, 1, 0, 0}};

    cout << "The Celebrity Problem : " << s.celebrityOptimal(matrix) << endl;

    return 0;
}