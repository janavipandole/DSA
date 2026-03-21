#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
    int largestRectangleArea(vector<int> &nums)
    {
        int maxArea = 0;
        int n = nums.size();
        stack<int> s;

        for (int i = 0; i < n; i++)
        {
            while (!s.empty() && nums[s.top()] > nums[i])
            {
                int element = nums[s.top()];
                s.pop();
                int NSE = i;
                int PSE = s.empty() ? -1 : s.top();
                maxArea = max(element * (NSE - PSE - 1), maxArea);
            }
            s.push(i);
        }

        while (!s.empty())
        {
            int NSE = n;
            int element = nums[s.top()];
            s.pop();
            int PSE = s.empty() ? -1 : s.top();
            maxArea = max(element * (NSE - PSE - 1), maxArea);
        }
        return maxArea;
    }
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        if (matrix.empty()) return 0;

        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> heights(m, 0);
        int maxArea = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == '1') heights[j] += 1;
                else heights[j] = 0;
            }

            maxArea = max(maxArea, largestRectangleArea(heights));
        }

        return maxArea;
    }
};
int main()
{
    Solution s;
    vector<vector<char>> matrix = {{'1', '0', '1', '0', '0'},
                                   {'1', '0', '1', '1', '1'},
                                   {'1', '1', '1', '1', '1'},
                                   {'1', '0', '0', '1', '0'}};
    cout << "Maximal Rectangle : " << s.maximalRectangle(matrix) << endl;
    return 0;
}