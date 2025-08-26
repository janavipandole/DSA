#include <iostream>
using namespace std;

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

int main()
{
    vector<int> nums = {6, 7, 8, 9, 10};
    int target = 9;
    cout << "Lower Bound Build in function: " << (upper_bound(nums.begin(), nums.end(), target)) - nums.begin() << endl;
    cout << getTarget(nums, target) << endl;
    return 0;
}