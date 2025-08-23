#include <iostream>
#include <vector>
using namespace std;

int pascalTriangle(int rows, int cols)
{
    rows--; // Adjust for 0-based indexing
    cols--; // Adjust for 0-based indexing
    int answer = 1;
    for (int i = 0; i < cols; i++)
    {
        answer *= (rows - i);
        answer /= (i + 1);
    }
    return answer;
}

vector<int> pascalTriangleRow(int row)
{
    vector<int> result;
    long long value = 1;
    result.push_back(value);
    for (int i = 1; i < row; i++)
    {
        value *= (row - i);
        value /= i;
        result.push_back(value);
    }
    return result;
}
vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> ans;
    for (int i = 1; i <= numRows; i++)
    {
        ans.push_back({pascalTriangleRow(i)});
    }
    return ans;
}
int main()
{
    // int rows = 5;
    // int cols = 3;
    // cout << "Pascal's Triangle value at (" << rows << ", " << cols << ") is: " << pascalTriangle(rows, cols) << endl;
    int row = 6; // Example row index
    vector<vector<int>> ans = generate(row);
    for (auto value : ans)
    {
        for (auto v : value)
        {
            cout << v << " ";
        }
        cout << endl;
    }
    return 0;
}