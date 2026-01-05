#include <iostream>
using namespace std;

class Solution
{
public:
    long long dividePlayers(vector<int> &skill)
    {
        sort(skill.begin(), skill.end());
        int n = skill.size();
        int totalSkill = skill[0] + skill[n - 1];

        long long ans = 0;

        int st = 0, end = n - 1;
        while (st < end)
        {
            if (skill[st] + skill[end] == totalSkill)
            {
                ans += skill[st] * skill[end];
            }
            else
            {
                return -1;
            }
            st++;
            end--;
        }
        return ans != 0 ? ans : -1;
    }
};

int main()
{
    Solution s;
    vector<int> skill = {1, 1, 2, 3};
    cout << "Divide Players Into Teams of Equal Skill : " << s.dividePlayers(skill) << endl;
    return 0;
}