#include <iostream>
using namespace std;
class Solution
{
public:
    bool isPrime(int n)
    {
        if (n <= 1)
            return false;

        for (int i = 2; i * i <= n; i++)
        {
            if (n % i == 0)
                return false;
        }
        return true;
    }
    bool checkPrimeFrequency(vector<int> &nums)
    {
        unordered_map<int, int> mpp;
        for (auto num : nums)
        {
            mpp[num]++;
        }
        for (auto &[key, count] : mpp)
        {
            if (isPrime(count))
                return true;
        }
        return false;
    }
};
int main()
{
    Solution s;
    vector<int> nums = {1, 2, 3, 4, 5, 4};
    cout << "Check if Any Element Has Prime Frequency : " << s.checkPrimeFrequency(nums) << endl;
    return 0;
}