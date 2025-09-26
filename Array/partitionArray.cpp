#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
class Solution
{
public:
    bool valid(vector<int> &temp, int maxElem, int k)
    {
        int minElem = temp[0];
        return (maxElem - minElem <= k);
    }
    int partitionArrayBrute(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        vector<int> temp;
        vector<vector<int>> ans;

        for (int i = 0; i < nums.size(); i++)
        {
            if (temp.empty())
            {
                temp.push_back(nums[i]);
            }
            else if (valid(temp, nums[i], k))
            {
                temp.push_back(nums[i]);
            }
            else
            {
                ans.push_back(temp);
                temp.clear();
                temp.push_back(nums[i]);
            }
        }
        if (!temp.empty())
        {
            ans.push_back(temp);
        }
        return ans.size();
    }

    int partitionArrayOptimal(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());

        int cnt = 0;
        int i = 0;
        int n = nums.size();
        while (i < n)
        {
            int mini = nums[i];
            cnt++;

            while (i < n && nums[i] - mini <= k)
            {
                i++;
            }
        }
        return cnt;
    }
};
int main()
{
    Solution s;
    vector<int> nums = {3, 6, 1, 2, 5};
    int k = 2;
    cout << "partition Array : " << s.partitionArrayBrute(nums, k) << endl;
    return 0;
}