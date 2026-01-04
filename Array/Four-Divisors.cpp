#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    pair<bool, int> Divisors(int num)
    {
        int sum = 0;
        int count = 0;

        for (int i = 1; i * i <= num; i++)
        {
            if (num % i == 0)
            {
                int d1 = i;
                int d2 = num / i;

                if (d1 == d2)
                {
                    count += 1;
                    sum += d1;
                }
                else
                {
                    count += 2;
                    sum += d1 + d2;
                }

                if (count > 4) return {false, 0};
            }
        }

        if (count == 4) return {true, sum};

        return {false, 0};
    }

    int sumFourDivisors(vector<int> &nums)
    {
        int ans = 0;
        for (auto num : nums)
        {
            pair<bool, int> index = Divisors(num);
            if (index.first == true)
            {
                ans += index.second;
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {21, 4, 7};
    cout << "Four Divisors : " << s.sumFourDivisors(nums) << endl;
    return 0;
}