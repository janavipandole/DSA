#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int secondLargestBrute(vector<int> &nums)
    {
        int largest1 = nums[nums.size() - 1];
        sort(nums.begin(), nums.end());

        for (int i = nums.size() - 2; i >= 0; i--)
        {
            if (largest1 != nums[i])
            {
                return nums[i];
            }
        }
        return -1;
    }

    int secondLargestBetter(vector<int> &nums)
    {
        int largest = -1, secondLargest = -1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > largest)
            {
                largest = nums[i];
            }
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > secondLargest && nums[i] < largest)
            {
                secondLargest = nums[i];
            }
        }
        // cout<<"largest : "<<largest<<endl;
        return secondLargest;
    }

    int secondLargestOptimal(vector<int> &nums)
    {
        int largest = nums[0], secondLargest = -1;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > largest)
            {
                secondLargest = largest;
                largest = nums[i];
            }
            if (nums[i] < largest && nums[i] > secondLargest)
            {
                secondLargest = nums[i];
            }
        }
        return secondLargest;
    }

    int secondSmallestBrute(vector<int> &nums)
    {
        int smallest = nums[nums.size() - 1];
        sort(nums.begin(), nums.end());

        for (int i = 1; i < nums.size(); i++)
        {
            if (smallest != nums[i])
            {
                return nums[i];
            }
        }
        return -1;
    }

    int secondSmallestBetter(vector<int> &nums)
    {
        int smalles = nums[0], secondSmallest = INT_MAX;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] < smalles)
            {
                smalles = nums[i];
            }
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] < secondSmallest && nums[i] != smalles)
            {
                secondSmallest = nums[i];
            }
        }
        return secondSmallest;
    }

    int secondSmallestOptimal(vector<int> &nums)
    {
        int smallest = nums[0], secondSmallest = INT_MAX;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] < smallest)
            {
                secondSmallest = smallest;
                smallest = nums[i];
            }
            if (nums[i] != smallest && nums[i] < secondSmallest)
            {
                secondSmallest = nums[i];
            }
        }
        return secondSmallest;
    }
};
int main()
{
    Solution s;
    vector<int> nums = {1, 2, 4, 7};
    vector<int> nums1 = {1, 2, 4, 7, 9, 8, 11, 8, 4};
    cout << "second Largest Brute : " << s.secondLargestBrute(nums) << endl;
    cout << "second Largest Better : " << s.secondLargestBetter(nums) << endl;
    cout << "second Largest optimal : " << s.secondLargestOptimal(nums) << endl;
    cout << "second Smallest  : " << endl;
    cout << "second Smallest Brute " << s.secondSmallestBrute(nums) << endl;
    cout << "second Largest Better : " << s.secondSmallestBetter(nums) << endl;
    cout << "second Largest optimal : " << s.secondSmallestOptimal(nums) << endl;
    return 0;
}