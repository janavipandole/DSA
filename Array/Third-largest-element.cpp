#include <iostream>
using namespace std;
// Better solution
int thirdLargestBetter(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    int largest = nums[nums.size() - 1], secondLargest = -1, ThirdLargest = -1;
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] != largest)
        {
            ThirdLargest = secondLargest;
            secondLargest = nums[i];
        }
        else if (nums[i] != secondLargest && nums[i] > ThirdLargest && nums[i] != largest)
        {
            ThirdLargest = nums[i];
        }
    }
    return ThirdLargest;
}

// Optimal solution
int thirdLargest(vector<int> &nums)
{
    int largest = nums[0], secondLargest = INT_MIN, ThirdLargest = INT_MIN;
    for (int i = 1; i < nums.size(); i++)
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
    }
    return nums.size() > 3 ? ThirdLargest : -1;
}
int main()
{
    vector<int> nums = {855, 450, 132, 359, 233, 825, 604, 481, 262, 337, 720, 525, 652, 300, 906, 219, 926, 906, 293, 864, 817, 498, 30, 639, 661};
    cout << "Third largest element : " << thirdLargestBetter(nums) << endl;
    cout << "Third largest element : " << thirdLargest(nums) << endl;

    return 0;
}