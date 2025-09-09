#include <iostream>
using namespace std;
int duplicateNumbersXOR(vector<int> &nums)
{
    unordered_map<int, int> mpp;
    for (auto num : nums)
        mpp[num]++;
    int XOR = 0;
    for (auto &[val, count] : mpp)
    {
        if (count == 2)
        {
            XOR ^= val;
        }
    }
    return XOR;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 1, 2,3};
    cout << "Find the XOR of Numbers Which Appear Twice : " << duplicateNumbersXOR(nums) << endl;
    return 0;
}