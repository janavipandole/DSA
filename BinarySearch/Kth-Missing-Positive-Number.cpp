#include <iostream>
#include <math.h>
using namespace std;
// Brute force solution TC = O(INT_MAX * nums.size()-1);
bool isPresent(vector<int> &nums, int val)
{
    for (auto num : nums)
    {
        if (num == val)
        {
            return true;
        }
    }
    return false;
}
int findKthPositiveBrute(vector<int> &nums, int k)
{
    int cnt = 0;
    for (int i = 1; i < INT_MAX; i++)
    {

        if (isPresent(nums, i) == false)
        {
            cnt++;
        }

        if (cnt == k)
        {
            return i;
        }
    }
    return -1;
}

// Better solution TC = O(nums.size()-1) LS
int findKthPositiveBetter(vector<int> &nums, int k)
{
    for (auto num : nums)
    {
        if (num <= k)
            k++;
        else
            return k;
    }
    return -1;
}
// Optimal solution TC = O(log) BS
int findKthPositiveOptimal(vector<int> &nums, int k)
{
    int low = 0, high = nums.size() - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        int missing = nums[mid] - (mid + 1);
        if(missing < k){
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }
    return low + k;
}
int main()
{
    vector<int> nums = {2, 3, 4, 7, 11};
    int k = 5;
    cout << "find Kth Positive : " << findKthPositiveBrute(nums, k) << endl;
    cout << "find Kth Positive : " << findKthPositiveBetter(nums, k) << endl;
    cout << "find Kth Positive : " << findKthPositiveOptimal(nums, k) << endl;

    return 0;
}