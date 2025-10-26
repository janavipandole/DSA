#include <iostream>
#include <set>
using namespace std;

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++)
        {
            set<int> s;
            for (int j = i; j < nums.size(); j++)
            {
                s.insert(nums[j]);
                if (s.size() == k)
                {
                    ans.push_back(*s.rbegin());
                    break;
                }
               
            }
        }
        return ans;
    }

     vector<int> maxSlidingWindow_Better(vector<int> &nums, int k)
    {
        vector<int> ans;
        multiset<int> s; // multiset because duplicates allowed

        for (int i = 0; i < nums.size(); i++)
        {
            s.insert(nums[i]);

            if (s.size() > k) s.erase(s.find(nums[i - k]));

            if (s.size() == k) ans.push_back(*s.rbegin());
        }

        return ans;
    }
};
int main()
{
    Solution s;
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    cout<<"Sliding Window Maximum : ";
    vector<int> ans = s.maxSlidingWindow_Better(nums, k);
    for (auto num : ans)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}