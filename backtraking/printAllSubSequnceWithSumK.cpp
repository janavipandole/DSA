#include <iostream>
using namespace std;

void subSequnce(vector<int> &nums, int target, int n, int index, vector<int> &ans)
{
    if (index == n)
    {
        if (target == 0)
        {
            for (auto val : ans)
            {
                cout << val << " ";
            }
            cout << endl;
        }
        return;
    }
    ans.push_back(nums[index]);
    subSequnce(nums, target - nums[index], n, index + 1, ans);

    ans.pop_back();
    subSequnce(nums, target, n, index + 1, ans);
}
void subSequnceWithSumk(vector<int> &nums, int target)
{
    vector<int> ans;
    int n = nums.size();
    subSequnce(nums, target, n, 0, ans);
}
int main()
{
    vector<int> nums = {1, 2, 1};
    subSequnceWithSumk(nums, 2);

    return 0;
}