#include <iostream>
#include <vector>
#include <map>
// C++ standard library headers: This project uses the <iostream>, <vector>, and <map> headers.
using namespace std;

int mejorityElemBrute(vector<int> &nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        int count = 0;
        for (int j = 0; j < nums.size(); j++)
        {
            if (nums[i] == nums[j])
            {
                count++;
            }
        }
        if (count > nums.size() / 2)
        {
            return nums[i];
        }
    }
    return -1; // Return -1 if no majority element is found
}

int mejorityElemBetter(vector<int> &nums)
{
    map<int, int> countMap;
    for (int i = 0; i < nums.size(); i++)
    {
        countMap[nums[i]]++;
    }
    for (auto pair : countMap)
    {
        if (pair.second > nums.size() / 2)
        {
            return pair.first;
        }
    }
    return -1; // Return -1 if no majority element is found
}

int mejorityElemOptimal(vector<int> &nums)
{
    int candidate = nums[0];
    int count = 1;

    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] == candidate)
        {
            count++;
        }
        else
        {
            count--;
            if (count == 0)
            {
                candidate = nums[i];
                count = 1;
            }
        }
    }

    // Verify the candidate
    count = 0;
    for (int num : nums)
    {
        if (num == candidate)
        {
            count++;
        }
    }

    return (count > nums.size() / 2) ? candidate : -1; // Return -1 if no majority element is found
}
int main()
{
    vector<int> nums = {3, 2, 3};
    cout << "The majority element is: " <<  mejorityElemBrute(nums) << endl;
    cout << "The majority element is: " << mejorityElemBetter(nums) << endl;
    cout << "The majority element is: " << mejorityElemOptimal(nums) << endl;
    return 0;
}