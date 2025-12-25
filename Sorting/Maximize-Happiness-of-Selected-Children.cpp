#include <iostream>
using namespace std;
class Solution
{
public:
    long long maximumHappinessSum(vector<int> &happiness, int k)
    {
        sort(happiness.rbegin(), happiness.rend());

        long long maximumSum = 0;
        for (int i = 0; i < k; i++)
        {
            if (happiness[i] - i > 0)
            {
                maximumSum += happiness[i] - i;
            }
        }

        return maximumSum;
    }
};
int main()
{
    Solution s;
    vector<int> nums = {2, 3, 4, 5};
    int k = 2;
    cout << "Maximize Happiness of Selected Children : " << s.maximumHappinessSum(nums, k) << endl;
    return 0;
}