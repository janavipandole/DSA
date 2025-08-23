#include <iostream>
#include <vector>
using namespace std;

vector<int> SpiralTraMat(vector<vector<int>> mat)
{
    vector<int> ans;
    int top = 0, bottom = mat[0].size() - 1;
    int left = 0, right = mat.size() - 1;

    while (top <= bottom && left <= right)
    {
        for (int j = left; j <= right; j++)
        {
            ans.push_back(mat[top][j]);
        }
        top++;

        for (int i = top; i <= bottom; i++)
        {
            ans.push_back(mat[i][right]);
        }
        right--;

        if (top <= bottom)
        {
            for (int j = right; j >= left; j--)
            {
                ans.push_back(mat[bottom][j]);
            }
            bottom--;
        }
        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
            {
                ans.push_back(mat[i][left]);
            }
            left++;
        }
    }
    return ans;
}
int main()
{
    vector<vector<int>> mat = {{1, 2, 3, 4, 5, 6},
                               {7, 8, 9, 10, 11, 12},
                               {13, 14, 15, 16, 17, 18},
                               {19, 20, 21, 22, 23, 24},
                               {25, 26, 27, 28, 29, 30},
                               {31, 32, 33, 34, 35, 36}};

    vector<int> ans = SpiralTraMat(mat);
    for (auto val : ans)
    {
        cout << val << " ";
    }
    return 0;
}