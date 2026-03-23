#include <iostream>
#include <vector>
#include <set>
#include <deque>
using namespace std;

class Solution
{
public:
    vector<int> maxSlidingWindowSol1(vector<int> &nums, int k)
    {
        vector<int> ans;
        multiset<int> s;

        for (int i = 0; i < nums.size(); i++)
        {
            s.insert(nums[i]);

            if (s.size() > k) s.erase(s.find(nums[i - k]));

            if (s.size() == k) ans.push_back(*s.rbegin());
        }

        return ans;
    }

    vector<int> maxSlidingWindowSol2(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> ans;
        deque<int> dq;

        for (int i = 0; i < nums.size(); i++)
        {
            if (!dq.empty() && dq.front() <= i - k){
                dq.pop_front();
            } 

            while(!dq.empty() && nums[dq.back()] <= nums[i]){
                dq.pop_back();
            }

            dq.push_back(i);

            if(i >= k-1) ans.push_back(nums[dq.front()]);
        }

        return ans;
    }
};
int main()
{
    Solution s;
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    cout << "Sliding Window Maximum : " << endl;

    vector<int> ans = s.maxSlidingWindowSol2(nums, k);
    for (auto num : ans)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}