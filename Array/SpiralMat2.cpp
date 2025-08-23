#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> SpiralTraMat(int n)
{
    vector<vector<int>> ans(n, vector<int>(n, 1));
    int top = 0, bottom = n - 1;
    int left = 0, right = n - 1;
    int cnt = 1;
    while (top <= bottom && left <= right)
    {
        for (int j = left; j <= right; j++)
        {
            ans[top][j] = cnt;
            cnt++;
        }
        top++;

        for (int i = top; i <= bottom; i++)
        {
            ans[i][right] = cnt;
            cnt++;
        }
        right--;

        if (top <= bottom)
        {
            for (int j = right; j >= left; j--)
            {
                ans[bottom][j] = cnt;
                cnt++;
            }
            bottom--;
        }
        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
            {
                ans[i][left] = cnt;
                cnt++;
            }
            left++;
        }
    }
    return ans;
}
int main()
{
    vector<vector<int>> ans = SpiralTraMat(3);

    for (auto val : ans)
    {
        for (auto num : val)
        {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}