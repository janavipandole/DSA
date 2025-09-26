#include <iostream>
#include <vector>
#include <set>
#include <math.h>
using namespace std;
class Solution
{
public:
    vector<int> mejorityElemBrute(vector<int> &nums)
    {
        vector<int> result;
        set<int> s;
        if (nums.empty())
        {
            return result;
        }

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
            if (cnt > nums.size() / 3 && s.find(nums[i]) == s.end())
            {
                result.push_back(nums[i]);
            }
            s.insert(nums[i]);
        }
        return result;
    }

    vector<int> mejorityElemBetter(vector<int> &nums)
    {
        vector<int> result;
        if (nums.empty())
        {
            return result;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (result.size() == 0 || result[0] != nums[i])
            {
                int cnt = 0;
                for (int j = 0; j < nums.size(); j++)
                {
                    if (nums[i] == nums[j])
                    {
                        cnt++;
                    }
                }
                if (cnt > nums.size() / 3)
                {
                    result.push_back(nums[i]);
                }
            }
            if (result.size() == 2)
            {
                break;
            }
        }

        return result;
    }

    vector<int> mejorityElemHashing(vector<int> &nums)
    {
        if (nums.empty())
        {
            return {};
        }
        vector<int> result;
        unordered_map<int, int> mpp;

        for (auto num : nums)
        {
            mpp[num]++;
            if ((mpp[num] > nums.size() / 3) && (result.size() == 0 || result[0] != num))
            {
                result.push_back(num);
            }
        }
        return result;
    }
    vector<int> findMajority(vector<int> &nums)
    {
        vector<int> result;
        if (nums.empty())
        {
            return result;
        }
        int cnt1 = 0, cnt2 = 0, elem1 = 0, elem2 = 0;
        //{1, 1, 1, 1, 3, 3, 2, 2, 2, 2}
        for (auto num : nums)
        {
            if (cnt1 == 0 && elem2 != num)
            {
                elem1 = num;
                cnt1 = 1;
            }
            else if (cnt2 == 0 && elem1 != num)
            {
                elem2 = num;
                cnt2 = 1;
            }
            else if (elem1 == num)
            {
                cnt1++;
            }
            else if (elem2 == num)
            {
                cnt2++;
            }
            else
            {
                cnt1--;
                cnt2--;
            }
        }
        cnt1 = 0;
        cnt2 = 0;
        for (auto num : nums)
        {
            if (num == elem1)
            {
                cnt1++;
            }
            if (num == elem2)
            {
                cnt2++;
            }
        }
        if (cnt1 > nums.size() / 3)
        {
            result.push_back(elem1);
        }
        if (cnt2 > nums.size() / 3)
        {
            result.push_back(elem2);
        }
        sort(result.begin(), result.end());
        return result;
    }
};
int main()
{
    Solution s;
    vector<int> arr = {1, 1, 1, 1, 3, 3, 2, 2, 2, 2};
    vector<int> result = s.findMajority(arr);
    for (auto &num : result)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}