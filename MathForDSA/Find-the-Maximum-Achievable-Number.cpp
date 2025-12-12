#include <iostream>
using namespace std;
class Solution
{
public:
    int theMaximumAchievableX(int num, int t)
    {
        int answer = num;

        while (t)
        {
            answer += 2;
            t--;
        }
        return answer;
    }
};
int main()
{
    Solution s;

    int num = 4, t = 1;
    cout << "Find the Maximum Achievable Number : " << s.theMaximumAchievableX(num, t) << endl;
    return 0;
}