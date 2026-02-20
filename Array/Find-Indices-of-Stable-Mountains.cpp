#include <iostream>
using namespace std;

class Solution
{
public:
    vector<int> stableMountains(vector<int> &height, int threshold)
    {
        vector<int> ans;
        for (int i = 1; i < height.size(); i++)
        {
            if (height[i - 1] > threshold)
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {10,1,10,1,10};
    int threshold = 2;
    cout << "Find Indices of Stable Mountains : " << endl;
    vector<int> ans = s.stableMountains(nums, threshold);
    for (auto num : ans)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}