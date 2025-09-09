#include <iostream>
using namespace std;
int count(int n)
{
    int cnt = 0;
    while (n > 0)
    {
        cnt += n & 1;
        n = n >> 1;
    }
    return cnt;
}
int sumIndicesWithKSetBits(vector<int> &nums, int k)
{
    int ans = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        if (count(i) == k)
        {
            ans += nums[i];
        }
    }
    return ans;
}
int main()
{
    vector<int> nums = {5, 10, 1, 5, 2};
    int k = 1;
    cout << "Sum of Values at Indices With K Set Bits : " << sumIndicesWithKSetBits(nums, k) << endl;
    return 0;
}