#include <iostream>
using namespace std;
class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int largest = INT_MIN, secondLargest = INT_MIN, ThirdLargest = INT_MIN;
        int minA = INT_MAX, minB = INT_MAX;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > largest)
            {
                ThirdLargest = secondLargest;
                secondLargest = largest;
                largest = nums[i];
            }
            else if (nums[i] > secondLargest)
            {
                ThirdLargest = secondLargest;
                secondLargest = nums[i];
            }
            else if (nums[i] > ThirdLargest)
            {
                ThirdLargest = nums[i];
            }

            if (nums[i] < minA)
            {
                minB = minA;
                minA = nums[i];
            }
            else if (nums[i] < minB)
                minB = nums[i];
        }
        return max(largest * secondLargest * ThirdLargest, largest * minA * minB);
    }
};
int main()
{
    Solution s;
    vector<int> nums = {852, -566, 182, -638, -693, -323};
    cout << "Three Great Candidates : " << s.maxProduct(nums) << endl;
    return 0;
}
