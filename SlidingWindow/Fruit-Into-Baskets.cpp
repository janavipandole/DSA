#include <iostream>
#include <set>
using namespace std;
class Solution
{
public:
    // Brute force solution
    int totalFruit_Brute(vector<int> &nums)
    {
        int maxFruits = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            set<int> s;
            for (int j = i; j < nums.size(); j++)
            {
                s.insert(nums[j]);
                if (s.size() > 2)
                    break;
                maxFruits = max(maxFruits, j - i + 1);
            }
        }
        return maxFruits;
    }

    // Optimal solution
    int totalFruit_Optimal(vector<int> &nums)
    {
        int maxFruits = 0, st = 0, end = 0;
        unordered_map<int, int> mpp;
        while (end < nums.size())
        {
            mpp[nums[end]]++;

            while (mpp.size() > 2)
            {
                mpp[nums[st]]--;
                if (mpp[nums[st]] == 0)
                    mpp.erase(nums[st]);
                st++;
            }
            maxFruits = max(maxFruits, end - st + 1);
            end++;
        }
        return maxFruits;
    }

    // Most Optimal solution
    int totalFruit_MostOptimal(vector<int> &nums)
    {
        int maxFruits = 0, st = 0, end = 0;
        unordered_map<int, int> mpp;
        while (end < nums.size())
        {
            mpp[nums[end]]++;

            if (mpp.size() > 2)
            {
                mpp[nums[st]]--;
                if (mpp[nums[st]] == 0)
                    mpp.erase(nums[st]);
                st++;
            }
            maxFruits = max(maxFruits, end - st + 1);
            end++;
        }
        return maxFruits;
    }
};
int main()
{
    Solution s;
    vector<int> nums = {3, 3, 3, 1, 2, 1, 1, 1, 2, 3, 3, 4};
    cout << "Fruit Into Baskets : " << s.totalFruit_Brute(nums) << endl;
    cout << "Fruit Into Baskets : " << s.totalFruit_Optimal(nums) << endl;
    cout << "Fruit Into Baskets : " << s.totalFruit_MostOptimal(nums) << endl;

    return 0;
}