#include <iostream>
using namespace std;
// Brute force solution
int hammingDistance(int x, int y)
{
    int XOR = x ^ y;
    int count = __builtin_popcount(XOR);
    return count;
}
int totalHammingDistance(vector<int> &nums)
{
    int sum = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            sum += hammingDistance(nums[i], nums[j]);
        }
    }
    return sum;
}
int main()
{
    vector<int> nums = {4, 14, 2};
    cout << "Total Hamming Distance : " << totalHammingDistance(nums) << endl;
    return 0;
}