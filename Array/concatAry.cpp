#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> concat(const vector<int> &nums)
    {
        vector<int> ans(nums.size() * 2);
        for (int i = 0; i < nums.size(); ++i)
        {
            ans[i] = nums[i];
            ans[i + nums.size()] = nums[i];
        }
        return ans;
    }

    vector<int> Permutation(const vector<int> &nums)
    {
        vector<int> ans(nums.size());
        for (int i = 0; i < nums.size(); ++i)
        {
            ans[i] = nums[nums[i]];
        }
        return ans;
    }

    vector<int> shuffle(vector<int> &nums, int n)
    {
        vector<int> ans(nums.size());
        int j = n;
        //{2, 5, 1, 3, 4, 7}
        int indexEven = 0;
        int indexOdd = 1;
        for (int i = 0; i < n; i++, j++)
        {
            ans[indexEven] = nums[i];
            ans[indexOdd] = nums[j];
            indexEven += 2;
            indexOdd += 2;
        }
        return ans;
    }

    int minimumOperations(vector<int> &nums)
    {
        int cnt = 0;
        for (auto num : nums)
        {
            if (num % 3 == 0)
            {
                continue;
            }
            while (num % 3 != 0)
            {
                int add = num + 1;
                int sub = num - 1;
                cnt++;
                if (add % 3 == 0 || sub % 3 == 0)
                {
                    break;
                }
            }
        }
        return cnt;
    }
};
int main()
{
    Solution s;
    vector<int> num = {1, 2, 3, 4};
    cout << "Minimum operations: " << s.minimumOperations(num) << endl;

    vector<int> nums1 = {1, 2, 3};
    vector<int> result1 = s.concat(nums1);
    for(int num : result1) {
        cout << num << " ";
    }
    cout << endl;

    vector<int> nums = {2, 5, 1, 3, 4, 7};
    vector<int> result = s.shuffle(nums , 3);
    for (int num : result)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}