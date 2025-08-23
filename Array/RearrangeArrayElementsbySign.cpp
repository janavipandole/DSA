#include <iostream>
#include <vector>
using namespace std;

vector<int> rearrangeArrayBrute(vector<int> &nums)
{
    vector<int> positive;
    vector<int> negative;
    vector<int> ans(nums.size(), 0);

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] > 0)
        {
            positive.push_back(nums[i]);
        }
        else
        {
            negative.push_back(nums[i]);
        }
    }
    for (int i = 0; i < nums.size() / 2; i++)
    {
        ans[i * 2] = positive[i];
        ans[i * 2 + 1] = negative[i];
    }
    return ans;
}

vector<int> rearrangeArrayOptimal(vector<int> &nums)
{
    vector<int> ans(nums.size(), 0);
    int posIndex = 0, negIndex = 1;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] > 0)
        {
            ans[posIndex] = nums[i];
            posIndex += 2;
        }
        else
        {
            ans[negIndex] = nums[i];
            negIndex += 2;
        }
    }
    return ans;
}
vector<int> rearrangeArrayVarityTwo(vector<int> &nums)
{
    vector<int> pos;
    vector<int> neg;
    vector<int> ans(nums.size(), 0);

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] > 0)
        {
            pos.push_back(nums[i]);
        }
        else
        {
            neg.push_back(nums[i]);
        }
    }
    if (pos.size() < neg.size())
    {
        for (int i = 0; i < pos.size(); i++)
        {
            ans[i * 2] = pos[i];
            ans[i * 2 + 1] = neg[i];
        }
        int idx = pos.size() * 2;
        for (int i = pos.size(); i < neg.size(); i++)
        {
            ans[idx++] = neg[i];
        }
    }
    else
    {
        for (int i = 0; i < neg.size(); i++)
        {
            ans[i * 2] = pos[i];
            ans[i * 2 + 1] = neg[i];
        }
        int idx = neg.size() * 2;
        for (int i = neg.size(); i < pos.size(); i++)
        {
            ans[idx++] = pos[i];
        }
    }
    return ans;
}

int main()
{
    vector<int> nums = {3, 1, -2, -5, 2, 4};
    vector<int> result = rearrangeArrayVarityTwo(nums);

    cout << "Rearranged array: ";
    for (int num : result)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}