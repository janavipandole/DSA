#include <iostream>
using namespace std;

class Solution
{
public:
    int scoreDifference(vector<int> &nums)
    {
        int first_player = 0;
        int second_player = 0;
        bool first_active = true, second_active = false;
        for (int i = 0; i < nums.size(); i++)
        {
            if ((i + 1) % 6 == 0)
            {
                swap(second_active, first_active);
            }
            if (nums[i] % 2 != 0)
            {
                swap(second_active, first_active);

                if (second_active)
                {
                    second_player += nums[i];
                }
                else
                {
                    first_player += nums[i];
                }
            }
            else
            {
                if (second_active)
                {
                    second_player += nums[i];
                }
                else
                {
                    first_player += nums[i];
                }
            }
        }
        return first_player - second_player;
    }
};
int main()
{
    Solution s;
    vector<int> nums = {2, 4, 2, 1, 2, 1};

    cout << "Find the Score Difference in a Game : " << s.scoreDifference(nums) << endl;

    return 0;
}
