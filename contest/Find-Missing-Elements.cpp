#include <iostream>
using namespace std;
class Solution
{
public:
    vector<int> findMissingElements(vector<int> &nums)
    {
        vector<int> ans;

        int smallest = *min_element(nums.begin(), nums.end());
        int largest = *max_element(nums.begin(), nums.end());
        vector<int> isPresent(largest + 1, 0);

        for (int i = 0; i < nums.size(); i++)
        {
            isPresent[nums[i]] = 1;
        }
        for (int i = smallest; i <= largest; i++)
        {
            if(isPresent[i] == 0) ans.push_back(i);
        }
        return ans;
    }
};
int main()
{
    Solution s;
    vector<int> nums = {5, 1};
    cout << "Find Missing Elements : " << endl;
    vector<int> ans = s.findMissingElements(nums);
    for(auto num : ans){
        cout<<num<<" ";
    }
    cout<<endl;
    return 0;
}