#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int countPartitions(vector<int> &nums)
    {
       int sum = 0;
       for(auto num : nums) sum += num;
       if (sum % 2 == 0) return nums.size() - 1;
       else return 0;
    }
};
int main()
{
    Solution s;
    vector<int> nums = {10,10,3,7,6};
    cout << "Count Partitions with Even Sum Difference : " << s.countPartitions(nums) << endl;
    return 0;
}