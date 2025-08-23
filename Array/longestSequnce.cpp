#include <iostream>
#include <vector>
#include <math.h>
#include <unordered_set>
using namespace std;

bool ls(vector<int> &nums, int x)
{
    for (auto num : nums)
    {
        if (num == x)
        {
            return true;
        }
    }
    return false;
}
int longestSqenBrute(vector<int> &nums)
{
    int longest = 1;
    int cnt = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        int x = nums[i];
        cnt = 1;
        while (ls(nums, x + 1) == true)
        {
            x += 1;
            cnt += 1;
        }
        longest = max(longest, cnt);
    }
    return longest;
}

int longestSqenBetter(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    int longest = 1;
    int cnt = 0;
    int smallest = INT_MIN;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] - 1 == smallest)
        {
            cnt += 1;
            smallest = nums[i];
        }
        else if (nums[i] != smallest)
        {
            cnt = 1;
            smallest = nums[i];
        }
        longest = max(longest, cnt);
    }
    return longest;
}

int longestSqenOptimal(vector<int> &nums)
{
    int longest = 1;
    unordered_set<int> s;

    for (int num : nums)
    {
        s.insert(num);
    }
    for (auto num : s)
    {
        if (s.find(num - 1) == s.end())
        {
            // {102, 4, 100, 101, 3, 2, 1};
            int cnt = 1;
            int x = num;
            while (s.find(x + 1) != s.end())
            {
                x += 1;
                cnt += 1;
            }
            longest = max(longest, cnt);
        }
    }
    return longest;
}

int main()
{
    vector<int> nums = {102, 4, 100, 1, 101, 3, 2, 1, 1};
    cout << "longest Sqen : " << longestSqenBrute(nums) << endl;
    cout << "longest Sqen : " << longestSqenBetter(nums) << endl;
    cout << "longest Sqen : " << longestSqenOptimal(nums) << endl;
    return 0;
}