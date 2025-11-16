#include <iostream>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    string reorganizeString(string s)
    {
        string ans = "";
        unordered_map<char, int> mpp;
        priority_queue<pair<int, char>> maxHeap;

        for (auto ch : s) mpp[ch]++;

        for (auto val : mpp) maxHeap.push({val.second, val.first});

        if (maxHeap.top().first > (s.size() + 1) / 2)return "";

        pair<int, char> prev = {0, '#'}; 

        while (!maxHeap.empty())
        {
            auto cur = maxHeap.top();
            maxHeap.pop();

            ans += cur.second;
            cur.first--;

            if (prev.first > 0)
            {
                maxHeap.push(prev);
            }

            prev = cur;
        }
        return ans;x
    }
};
int main()
{
    Solution s;
    string str = "vvvlo";
    cout << "Reorganize String : " << s.reorganizeString(str) << endl;
    return 0;
}