#include <iostream>
using namespace std;
void rearrange(vector<int> &nums)
{
    vector<int> pos, neg;

    for (auto num : nums)
    {
        if (num < 0)
            neg.push_back(num);
        else
            pos.push_back(num);
    }
    if (neg.size() < pos.size())
    {
        for (int i = 0; i < neg.size(); i++)
        {
            nums[i * 2] = pos[i];
            nums[i * 2 + 1] = neg[i];
        }
        int index = neg.size() * 2;
        for (int i = neg.size(); i < pos.size(); i++)
        {
            nums[index] = pos[i];
            index++;
        }
    }
    else
    {
        for (int i = 0; i < pos.size(); i++)
        {
            nums[i * 2] = pos[i];
            nums[i * 2 + 1] = neg[i];
        }
        int index = pos.size() * 2;
        for (int i = pos.size(); i < neg.size(); i++)
        {
            nums[index] = neg[i];
            index++;
        }
    }
}
int main()
{
    vector<int> nums = {-5, -2, 5, 2, 4, 7, 1, 8, 0, -8};
    rearrange(nums);
    for (auto num : nums)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}