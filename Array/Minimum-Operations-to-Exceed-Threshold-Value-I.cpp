#include <iostream>
using namespace std;
int minOperations(vector<int> &nums, int k)
{
    int minOper = 0;
    int n = nums.size();

    for (auto num : nums)
    {
        if (num >= k)
            minOper++;
    }
    return n - minOper;
}
int main()
{
    vector<int> nums = {2, 11, 10, 1, 3};
    int k = 10;
    cout << "Minimum Operations to Exceed Threshold Value I : " << minOperations(nums, k) << endl;
    return 0;
}