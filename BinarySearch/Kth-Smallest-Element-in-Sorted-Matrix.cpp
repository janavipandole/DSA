#include <iostream>
using namespace std;
// Brute force solution
int kthSmallestBrute(vector<vector<int>> &mat, int k)
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
    return nums[k-1];
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

int countPresent(vector<vector<int>> &mat, int num)
{
    int cnt = 0;
    for (int i = 0; i < mat.size(); i++)
    {
        cnt += getTarget(mat[i], num);
    }
    return cnt;
}
int kthSmallestOptimal(vector<vector<int>> &mat, int k)
{
    int n = mat.size();
    int m = mat[0].size();
    int ans = 0;
    int low = mat[0][0], high = mat[n - 1][n - 1];
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (countPresent(mat, mid) <= k-1)
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
    vector<vector<int>> nums = {{1, 5, 9}, {10, 11, 13}, {12, 13, 15}};
    int k = 8;
    cout << "median : " << kthSmallestBrute(nums, k) << endl;
    cout << "median : " << kthSmallestOptimal(nums, k) << endl;

    return 0;
}