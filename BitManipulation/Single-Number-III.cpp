#include <iostream>
using namespace std;
// Brute force solutions
vector<int> singleNumberIIIBrute(vector<int> &nums)
{
    vector<int> ans;
    unordered_map<int, int> mpp;

    for (auto num : nums)
    {
        mpp[num]++;
    }

    for (auto val : mpp)
    {
        if (val.second == 1)
        {
            ans.push_back(val.first);
        }
    }
    return ans;
}
// Optimal solutions
vector<int> singleNumberIIIOptimal(vector<int> &nums)
{
    long long XOR = 0;

    for (auto num : nums)
        XOR ^= num;

    int rightMostBit = ((XOR & (XOR - 1)) ^ XOR);
    int bit1 = 0, bit2 = 0;

    for (auto num : nums)
    {
        if (num & rightMostBit)
            bit1 ^= num;
        else
            bit2 ^= num;
    }
    return {bit1, bit2};
}
int main()
{
    vector<int> nums = {1, 2, 1, 3, 2, 5};
    vector<int> ans = singleNumberIIIOptimal(nums);
    cout << "single Number III : " << endl;
    for (auto num : ans)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}