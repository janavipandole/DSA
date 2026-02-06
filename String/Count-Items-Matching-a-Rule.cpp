#include <iostream>
using namespace std;

class Solution
{
public:
    int countMatches(vector<vector<string>> &items, string ruleKey, string ruleValue)
    {
        int count = 0;

        for (int i = 0; i < items.size(); i++)
        {
            if(ruleKey == "type" && ruleValue == items[i][0]) count++;
            else if (ruleKey == "color" && ruleValue == items[i][1]) count++;
            else if (ruleKey == "name" && ruleValue == items[i][2]) count++;
        }
        return count;
    }
};

int main()
{
    Solution s;
    vector<vector<string>> items = {{"phone", "blue", "pixel"}, {"computer", "silver", "lenovo"}, {"phone", "gold", "iphone"}};
    string ruleKey = "color", ruleValue = "silver";
    cout << "Count Items Matching a Rule : " << s.countMatches(items,ruleKey,ruleValue) << endl;

    return 0;
}