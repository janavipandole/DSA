#include <iostream>
#include <vector>
#include <set>
using namespace std;

bool checkSorted(vector<int> &nums)
{
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i - 1] > nums[i])
        {
            return false;
        }
    }
    return true;
}

int removeDuplicateBrute(vector<int> &nums)
{
    set<int> s;
    for (int i = 1; i < nums.size(); i++)
    {
        s.insert(nums[i]);
    }
    int index = 0;
    for (auto i : s)
    {
        nums[index] = i;
        index++;
    }
    return index;
}

int removeDuplicateOptimal(vector<int> &nums)
{
    int k = 0;
    for (int i = 1; i < nums.size(); i++)
    {
        cout<<nums[i]<<" ";
        if (nums[i - 1] != nums[i])
        {
            nums[k] = nums[i];
            k++;
        }
    }
    cout << endl;
    return k + 1;
}
int main()
{
    vector<int> nums = {1, 2, 3, 1, 5, 6, 7, 8};
    vector<int> nums1 = {
        1,
        1,
        2,
        2,
        2,
        3,
        3,
        3,
        3,
    };

    cout << "is array sorted : ? " << checkSorted(nums) << endl;
    cout << removeDuplicateBrute(nums1) << endl;
    return 0;
}