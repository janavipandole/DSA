#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> repeatingMissingBrute(vector<int> &nums)
    {
        int missing = 0;
        int repeating = 0;
        vector<int> ans(2, 0);
        int n = nums.size();
        for (int j = 1; j <= n; j++)
        {
            int cnt = 0;
            for (int i = 0; i < n; i++)
            {
                if (nums[i] == j)
                {
                    cnt++;
                }
                if (cnt == 2)
                {
                    repeating = j;
                    break;
                }
            }
            if (cnt == 0)
            {
                missing = j;
                break;
            }
            else if (missing != 0 && repeating != 0)
            {
                ans[0] = repeating;
                ans[1] = missing;
                return ans;
            }
        }
        return {};
    }

    vector<int> repeatingMissingBetter(vector<int> &nums)
    {

        vector<int> store(nums.size() + 1);
        vector<int> ans(2, 0);

        for (auto num : nums)
        {
            store[num]++;
        }

        for (int i = 1; i < store.size(); i++)
        {
            if (store[i] == 2)
            {
                ans[0] = i;
            }
            if (store[i] == 0)
            {
                ans[1] = i;
            }
        }
        return ans;
    }

    vector<int> repeatingMissingOptimal(vector<int> &nums)
    {
        long long n = nums.size();
        long long originalSum = 0;
        long long originalSumSquear = 0;
        for (long long i = 1; i <= n; i++)
        {
            originalSum += i;
            originalSumSquear += (i * i);
        }
        vector<int> ans(2, 0);

        long long givenSum = 0;
        long long givenSumSquear = 0;
        for (auto num : nums)
        {
            givenSum += num;
            givenSumSquear += (num * num);
        }
        long long value1 = givenSum - originalSum; // x - y
        long long value2 = givenSumSquear - originalSumSquear;
        value2 = value2 / value1;            // x + y
        long long x = (value1 + value2) / 2; // x = (x - y + x + y) / 2
        long long y = x - value1;            // y = x - (x - y)
        ans[0] = x;                          // repeating
        ans[1] = y;                          // missing
        return ans;
    }
};
int main()
{
    Solution s;
    vector<int> arr = {4, 3, 6, 2, 1, 1};
    vector<int> ans = s.repeatingMissingOptimal(arr);
    for (auto num : ans)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}