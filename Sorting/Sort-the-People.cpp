#include <iostream>
#include <map>
using namespace std;

class Solution
{
public:
    vector<string> sortPeopleBrute(vector<string> &names, vector<int> &heights)
    {
        map<int, string> mpp;
        int n = names.size();
        int index = 0;

        for (int i = 0; i < n; i++)
        {
            mpp[heights[i]] = names[i];
        }

        for (auto &[height, name] : mpp)
        {
            names[index++] = name;
        }
        reverse(names.begin(), names.end());

        return names;
    }

    vector<string> sortPeopleOptimal(vector<string> &names, vector<int> &heights)
    {
        vector<pair<int, string>> details;

        for (int i = 0; i < heights.size(); i++)
        {
            details.push_back({heights[i], names[i]});
        }

        sort(details.begin(), details.end(), greater<pair<int, string>>());

        for (int i = 0; i < names.size(); i++)
        {
            names[i] = details[i].second;
        }

        return names;
    }
};

int main()
{
    Solution s;
    vector<int> heights = {180, 165, 170};
    vector<string> names = {"Mary", "John", "Emma"};
    cout << "Sort the People : " << endl;
    vector<string> ans = s.sortPeopleOptimal(names, heights);
    for (auto name : ans)
    {
        cout << name << " ";
    }
    cout << endl;
    return 0;
}