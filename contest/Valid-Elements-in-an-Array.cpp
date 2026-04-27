#include <iostream>
using namespace std;
class Solution
{
public:
    vector<int> findValidElements(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> left(n, -1);
        vector<int> right(n, -1);
        int leftMax = -1;
        int rightMax = -1;
        vector<int> answer;

        for (int i = 1; i < n - 1; i++)
        {
            if (nums[i - 1] >= nums[i] || nums[i] <= leftMax)
            {
                leftMax = max(leftMax, nums[i - 1]);
                left[i] = leftMax;
            }
        }
        for (int i = n - 2; i > 0; i--)
        {
            if (nums[i] <= nums[i + 1] || nums[i] <= rightMax)
            {
                rightMax = max(rightMax, nums[i + 1]);
                right[i] = rightMax;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (left[i] == -1 || right[i] == -1)
            {
                answer.push_back(nums[i]);
            }
        }

        return answer;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {10, 10, 10, 10};
    cout << "Total Waviness of Numbers in Range I : " << endl;
    vector<int> answer = s.findValidElements(nums);
    for (auto num : answer)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}