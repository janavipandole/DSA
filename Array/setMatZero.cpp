#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    void markRowsZero(int i, int m, vector<vector<int>> &nums)
    {
        for (int j = 0; j < m; j++)
        {
            if (nums[i][j] != 0)
            {
                nums[i][j] = -1; // Marking for later update
            }
        }
    }

    void markColsZero(int j, int n, vector<vector<int>> &nums)
    {
        for (int i = 0; i < n; i++)
        {
            if (nums[i][j] != 0)
            {
                nums[i][j] = -1; // Marking for later update
            }
        }
    }

    void setMatZeroBrute(vector<vector<int>> &nums)
    {
        int n = nums.size();
        int m = nums[0].size();

        // First pass: Mark rows and columns
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (nums[i][j] == 0)
                {
                    markRowsZero(i, m, nums);
                    markColsZero(j, n, nums);
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (nums[i][j] == -1)
                {
                    nums[i][j] = 0;
                }
                cout << nums[i][j] << " ";
            }
            cout << endl;
        }
    }

    void setMatZeroBetter(vector<vector<int>> &nums)
    {
        int n = nums.size();
        int m = nums[0].size();
        vector<int> row(n, 0);
        vector<int> col(m, 0);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (nums[i][j] == 0)
                {
                    row[i] = -1;
                    col[j] = -1;
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (row[i] == -1 || col[j] == -1)
                {
                    nums[i][j] = 0;
                }
                cout << nums[i][j] << " ";
            }
            cout << endl;
        }
    }

    void setZeroes(vector<vector<int>> &mat)
    {
        int col0 = 1;
        int n = mat.size();
        int m = mat[0].size();
        // col[m] == mat[0][...]
        // row[n] == mat[...][0]
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] == 0)
                {
                    // mark i-th row
                    mat[i][0] = 0;
                    // mark j-th cols

                    if (j != 0)
                    {
                        mat[0][j] = 0;
                    }
                    else
                    {
                        col0 = 0;
                    }
                }
            }
        }

        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                if (mat[i][j] != 0)
                {
                    // check for row and col
                    if (mat[i][0] == 0 || mat[0][j] == 0)
                    {
                        mat[i][j] = 0;
                    }
                }
            }
        }

        if (mat[0][0] == 0)
        {
            for (int j = 0; j < m; j++)
            {
                mat[0][j] = 0;
            }
        }

        if (col0 == 0)
        {
            for (int i = 0; i < n; i++)
            {
                mat[i][0] = 0;
            }
        }
    }
};
int main()
{
    Solution s;
    vector<vector<int>> nums = {{1, 1, 1, 1}, {1, 1, 0, 1}, {1, 1, 0, 1}, {1, 1, 1, 1}};
    s.setZeroes(nums);
    for (auto i : nums)
    {
        for (auto num : i)
        {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}
