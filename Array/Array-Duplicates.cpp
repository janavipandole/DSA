#include <iostream>
using namespace std;
class Solutions
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        unordered_map<int, int> mpp;
        vector<int> ans;
        for (auto num : nums)
        {
            mpp[num]++;
        }

        for (auto(val) : mpp)
        {
            if (val.second == 2)
            {
                ans.push_back(val.first);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
int main()
{
    Solutions s;
    vector<int> nums = {2, 3, 1, 2, 3};
    vector<int> ans = s.findDuplicates(nums);
    cout << "findDuplicates : ";
    for (auto num : ans)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}