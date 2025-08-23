#include <iostream>
#include <vector>
using namespace std;

int findMaxConsecutiveOnes(vector<int> &nums)
{
    int maxCnt = 0, cnt = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 1)
        {
            cnt++;
            maxCnt = max(cnt, maxCnt);
        }
        else
        {
            cnt = 0;
        }
    }
    return maxCnt;
}

int numberApperOnceAndOtherTwiceBrute(vector<int> &nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        int cnt = 0;
        for (int j = 0; j < nums.size(); j++)
        {
            if (nums[i] == nums[j])
            {
                cnt++;
            }
        }
        if (cnt == 1)
        {
            return nums[i];
        }
    }
    return -1;
}

int numberApperOnceAndOtherTwiceOptimal(vector<int> &nums)
{
    int xor1 = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        xor1 ^= nums[i];
    }
    return xor1;
}

int main()
{
    vector<int> nums = {1, 1, 2, 3, 3, 4, 4};
    cout << "find number Apper Once And Other Twice : " << numberApperOnceAndOtherTwiceBrute(nums) << endl;
    return 0;
}