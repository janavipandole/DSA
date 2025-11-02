#include <iostream>
using namespace std;
class Solution
{
public:
    int minimumOperations(vector<int> &nums)
    {
        int cnt = 0;
        int x = 0;
        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0) continue;
            x = nums[i];
            cnt++;
            for(int j = i; j < nums.size(); j++){
                nums[j] -= x;
            }
        }
        return cnt;
    }
};
int main()
{
    Solution s;
    vector<int> nums = {1, 5, 0, 3, 5};
    cout << "Make Array Zero by Subtracting Equal Amounts : " << s.minimumOperations(nums) << endl;
    return 0;
}