#include <iostream>
using namespace std;
class Solution
{
public:
    int numSubarrayProductLessThanK_Brute(vector<int> &nums, int k)
    {
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            long long int product = 1;
            for (int j = i; j < nums.size(); j++)
            {
                product *= nums[j];
                if (product >= k) break;
                cnt++;
            }
        }
        return cnt;
    }

    int numSubarrayProductLessThanK_Optimal(vector<int> &nums, int k)
    {
        if (k <= 1) return 0;
        int cnt = 0, end = 0, st = 0;
        long long int product = 1;
        while(end < nums.size()){
            product *= nums[end];

            while (product >= k){
                product /= nums[st];
                st++;
            }
            cnt += end - st + 1;
            end++;
        }
        return cnt;
    }
};
int main()
{
    Solution s;
    vector<int> nums = {10,9,10,4,3,8,3,3,6,2,10,10,9,3};
    int k = 19;
    cout<<"Subarray Product Less Than K : "<<s.numSubarrayProductLessThanK_Brute(nums, k)<<endl;
    cout<<"Subarray Product Less Than K : "<<s.numSubarrayProductLessThanK_Optimal(nums, k)<<endl;

    return 0;
}