#include <iostream>
using namespace std;
// Brute force solution
int medianBrute(vector<vector<int>> &mat)
{
    vector<int> nums;
    for (int i = 0; i < mat.size(); i++)
    {
        for (int j = 0; j < mat[0].size(); j++)
        {
            nums.push_back(mat[i][j]);
        }
    }
    sort(nums.begin(), nums.end());
    return nums[nums.size() / 2];
}
// Optimal force solution
// Upper bound
int getTarget(vector<int> &nums, int target)
{
    int low = 0;
    int high = nums.size() - 1;
    int answer = nums.size();
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (nums[mid] > target)
        {
            answer = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return answer;
}
// count present no <= num
int countPresent(vector<vector<int>> &mat, int num)
{
    int cnt = 0;
    for (int i = 0; i < mat.size(); i++)
    {
        cnt += getTarget(mat[i], num);
    }
    return cnt;
}

int medianOptimal(vector<vector<int>> &mat)
{
    int low = INT_MAX, high = INT_MIN;
    int n = mat.size();
    int m = mat[0].size();
    int median = m * n / 2;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        low = min(low, mat[i][0]);
        high = max(high, mat[i][m - 1]);
    }

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (countPresent(mat, mid) <= median)
        {
            low = mid + 1;
        }
        else
        {
            ans = mid;
            high = mid - 1;
        }
    }
    return ans;
}

int main()
{
    vector<vector<int>> nums = {{1, 3, 5}, {2, 6, 9}, {3, 6, 9}};
    cout << "median : " << medianBrute(nums) << endl;
    cout << "median : " << medianOptimal(nums) << endl;

    return 0;
}