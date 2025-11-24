#include <iostream>
using namespace std;
class Solution
{
public:
    int cntWaviness(vector<int> &nums)
    {
        int balance = 0;
        int totalCount = 0;

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > nums[i - 1])
            {
                balance++;
            }
            else if (nums[i] < nums[i - 1])
            {
                balance--;
            }
            else
            {
                continue;
            }

            if (balance == 0)
            {
                totalCount++;

                if (nums[i] > nums[i - 1])
                {
                    balance = 1;
                }
                else
                {
                    balance = -1;
                }
            }
        }

        return totalCount;
    }

    int totalWaviness(int num1, int num2)
    {
        int count = 0;

        for (int i = num1; i <= num2; i++)
        {
            vector<int> nums;
            int dummy = i;

            while (dummy > 0)
            {
                nums.push_back(dummy % 10);
                dummy /= 10;
            }

            count += cntWaviness(nums);
        }

        return count;
    }
};

int main()
{
    Solution s;
    int num1 = 5872, num2 = 5921;
    cout << "Total Waviness of Numbers in Range I : " << s.totalWaviness(num1, num2) << endl;
    return 0;
}