#include <iostream>
using namespace std;
class Solution
{
public:
    int getIndex(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1) return 0;
        if (nums[0] > nums[1]) return 0;
        if (nums[n - 1] > nums[n - 2]) return n - 1;

        int low = 1, high = n - 1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])return mid;

            if (nums[mid] > nums[mid - 1])low = mid + 1;
            else high = mid - 1;
        }
        return -1;
    }
    int compareBitonicSums(vector<int> &nums)
    {
        int n = nums.size();
        int peakIndex = getIndex(nums);
        long long asceSum = 0, desceSum = 0;
        for (int i = 0; i < n; i++)
        {
            if (i <= peakIndex) asceSum += nums[i];
            if (i >= peakIndex)desceSum += nums[i];
        }

        if (asceSum > desceSum) return 0;
        if (asceSum < desceSum) return 1;
        return -1;
    }
};
int main()
{
    Solution s;
    vector<int> nums = {2, 4, 5, 2};
    cout << "Compare Sums of Bitonic Parts : " << s.compareBitonicSums(nums) << endl;
    return 0;
}