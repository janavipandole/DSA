#include <iostream>
#include <vector>
using namespace std;

void nextPermutation(vector<int> &nums)
{

    int index = -1;
    int n = nums.size();
    for (int i = n - 2; i >= 0; i--)
    {
        if (nums[i] < nums[i + 1])
        {
            index = i;
            break;
        }
    }

    if (index == -1)
    {
        reverse(nums.begin(), nums.end());
        return;
    }

    for (int i = n - 1; i > index; i--)
    {
        if (nums[i] > nums[index])
        {
            swap(nums[i], nums[index]);
            break;
        }
    }
    reverse(nums.begin() + index + 1, nums.end());
    return;
}

vector<int> leaderInAry(vector<int> &nums)
{
    vector<int> ans;
    int n = nums.size();

    //{10, 22, 12, 0, 3, 6}
    for (int i = 0; i < nums.size(); i++)
    {
        bool isGrater = false;
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[i] < nums[j])
            {
                isGrater = true;
                break;
            }
        }
        if (isGrater == false)
        {
            ans.push_back(nums[i]);
        }
    }
    return ans;
}

vector<int> leaders(vector<int> &nums)
{
    vector<int> ans;
    int n = nums.size();
    int maxUp = INT_MIN;
    // 10, 22, 12, 0, 3, 6
    for (int i = n - 1; i >= 0; i--)
    {
        if (maxUp > nums[i])
        {
            ans.push_back(nums[i]);
        }
         maxUp = max(maxUp, nums[i]);
    }
    return ans;
}
int main()
{
    vector<int> nums = {10, 22, 12, 0, 3, 6};

    vector<int> ans = leaders(nums);
    for (auto num : ans)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}