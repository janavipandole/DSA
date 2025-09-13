#include <iostream>
using namespace std;
double findMaxAverage(vector<int> &nums, int k)
{
    int sum = 0;
    for (int i = 0; i < k; ++i)
    {
        sum += nums[i];
    }
    int maxSum = sum;
    for (int i = k; i < nums.size(); ++i)
    {
        sum += nums[i] - nums[i - k];
        maxSum = max(maxSum, sum);
    }
    double ans = (static_cast<double>(maxSum) / k);
    return ans;
}
int main()
{
    vector<int> nums = {7, 4, 5, 8, 8, 3, 9, 8, 7, 6};
    int k = 7;
    cout << "Maximum Average Subarray I : " << findMaxAverage(nums, k) << endl;
    return 0;
}