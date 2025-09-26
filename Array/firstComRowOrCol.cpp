#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    bool row(vector<vector<int>> &mat, int r)
    {
        for (int c = 0; c < mat[0].size(); c++)
        {
            if (mat[r][c] > 0)
            {
                return false;
            }
        }
        return true;
    }

    bool column(vector<vector<int>> &mat, int c)
    {
        for (int r = 0; r < mat.size(); r++)
        {
            if (mat[r][c] > 0)
            {
                return false;
            }
        }
        return true;
    }

    int firstCompleteIndexBetter(vector<int> &arr, vector<vector<int>> &mat)
    {
        unordered_map<int, pair<int, int>> mpp;

        for (int i = 0; i < mat.size(); i++)
        {
            for (int j = 0; j < mat[0].size(); j++)
            {
                int val = mat[i][j];
                mpp[val] = {i, j};
            }
        }

        for (int i = 0; i < arr.size(); i++)
        {
            int val = arr[i];
            int r = -1, c = -1;
            if (mpp.find(val) != mpp.end())
            {
                c = mpp[val].second;
                r = mpp[val].first;
            }
            mat[r][c] = -1;
            if (row(mat, r) || column(mat, c))
            {
                return i;
            }
        }
        return 0;
    }

    int firstCompleteIndexBrute(vector<int> &arr, vector<vector<int>> &mat)
    {
        unordered_map<int, pair<int, int>> mpp;

        for (int i = 0; i < mat.size(); i++)
        {
            for (int j = 0; j < mat[0].size(); j++)
            {
                int val = mat[i][j];
                mpp[val] = {i, j};
            }
        }

        vector<int> row(mat.size(), 0);
        vector<int> col(mat[0].size(), 0);
        for (int i = 0; i < arr.size(); i++)
        {
            int val = arr[i];
            int r = -1, c = -1;
            if (mpp.find(val) != mpp.end())
            {
                c = mpp[val].second;
                r = mpp[val].first;
            }
            row[r]++;
            col[c]++;

            if (row[r] == mat[0].size() || col[c] == mat.size())
            {
                return i;
            }
        }
        return 0;
    }
};
int main()
{
    Solution s;
    vector<int> arr = {1, 3, 4, 2};
    vector<vector<int>> mat = {{1, 4}, {2, 3}};
    cout << "first Complete Index : " << s.firstCompleteIndexBetter(arr, mat) << endl;
    return 0;
}