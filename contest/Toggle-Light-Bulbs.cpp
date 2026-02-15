#include <iostream>
using namespace std;

class Solution
{
public:
    vector<int> toggleLightBulbs(vector<int> &bulbs)
    {
        vector<int> ans;
        unordered_map<int, int> hash;
        for (auto bulb : bulbs)
        {
            hash[bulb]++;
        }
        for (auto &[key, count] : hash)
        {
            if (count % 2 != 0)
            {
                ans.push_back(key);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> bulbs = {1, 2};
    cout << "Toggle Light Bulbs : " << endl;
    vector<int> ans = s.toggleLightBulbs(bulbs);
    for (auto num : ans)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}