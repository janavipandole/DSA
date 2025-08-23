#include <iostream>
#include <vector>
#include <map>
using namespace std;

int missingElemBrute(vector<int> &nums, int n)
{
    int flag = 0;
    for (int i = 1; i <= n; i++)
    {
        flag = 0;
        for (int j = 0; j < n; j++)
        {
            if (nums[j] == i)
            {
                break;
            }
            flag = i;
        }
    }
    return flag;
}

int missingElemBetter(vector<int> &nums, int n)
{
    vector<bool> present(n + 1, false);

    for (int num : nums)
    {
        present[num] = true;
    }

    for (int i = 1; i <= n; i++)
    {
        if (!present[i])
        {
            return i;
        }
    }

    return -1;
}

int missingElemOptimal1(vector<int> &nums, int n)
{
    int realSum = n * (n + 1) / 2;
    int giveSum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        giveSum += nums[i];
    }
    cout << realSum << " - " << giveSum << endl;

    return realSum - giveSum;
}
int missingElemOptimal2(vector<int> &nums, int n)
{
    int xor1 = 0, xor2;
    for (int i = 0; i < nums.size(); i++)
    {
        xor2 ^= nums[i];
        xor1 ^= i+1;
    }
    xor1 ^= n;
    return xor1 ^ xor2;
}
int main()
{
    vector<int> nums1 = {1, 2, 5, 3};
    cout << missingElemOptimal2(nums1, 5) << endl;
    vector<int> nums2 = {1, 2, 5, 4};
    cout << missingElemOptimal2(nums2, 5) << endl;
    return 0;
}