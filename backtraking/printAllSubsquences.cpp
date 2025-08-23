#include <iostream>
using namespace std;

void printAllSs(vector<int> &nums, int index, int n, vector<int> &ans)
{
    if (index == n)
    {
        cout << "[";
        for (auto val : ans)
        {
            cout << val;
        }
        cout << "]"<<endl;
        return;
    }

    printAllSs(nums, index + 1, n, ans);
    ans.push_back(nums[index]);
    printAllSs(nums, index + 1, n, ans);

    ans.pop_back();
}
void printAllSubsqu(vector<int> &nums)
{
    vector<int> ans;
    printAllSs(nums, 0, nums.size(), ans);
    cout << endl;
    return;
}

int main()
{
    vector<int> nums = {3, 1, 2};
    printAllSubsqu(nums);
    return 0;
}