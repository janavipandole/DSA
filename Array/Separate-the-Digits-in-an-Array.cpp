#include <iostream>
using namespace std;
class Solution
{
public:
    vector<int> separateDigits(vector<int> &nums)
    {
        vector<int> answer;
        for (int i = 0; i < nums.size(); i++)
        {
            string num = to_string(nums[i]);
            for(int j = 0; j < num.size();j++){
                answer.push_back(num[j]-'0');
            }
        }
        return answer;
    }
};
int main()
{
    Solution s;
    vector<int> nums = {13, 25, 83, 77};
    cout << "Separate the Digits in an Array : " << endl;
    vector<int> ans = s.separateDigits(nums);
    for (int num : ans)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}