#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution
{
public:
    int firstUniqueEven(vector<int> &nums)
    {
        unordered_map<int, int> count;
        queue<int> qu;
        for (int i = 0; i < nums.size(); i++)
        {
            if (count.find(nums[i]) == count.end() && nums[i] % 2 == 0)
            {
                qu.push(nums[i]);
            }

            if (nums[i] % 2 == 0)
            {
                count[nums[i]]++;
            }
        }
        while (!qu.empty() && count[qu.front()] != 1)
        {
            qu.pop();
        }
        return qu.empty() ? -1 : qu.front();
    }
};
int main()
{
    Solution s;
    vector<int> nums = {4, 6, 6};
    cout << "First Unique Even Element : " << s.firstUniqueEven(nums) << endl;
    return 0;
}
