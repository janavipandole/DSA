#include <iostream>
using namespace std;
class Solution
{
public:
    string frequencySort(string s)
    {
        unordered_map<char, int> mpp;
        priority_queue<pair<int, char>> maxHeap;
        string ans = "";
        for (auto ch : s)
        {
            mpp[ch]++;
        }
        for (auto &[val, count] : mpp)
        {
            maxHeap.push({count, val});
        }
        while (maxHeap.size() > 0)
        {
            for (int i = 0; i < maxHeap.top().first; i++)
            {
                ans += maxHeap.top().second;
            }
            maxHeap.pop();
        }
        return ans;
    }
};
int main()
{
    Solution s;
    string str = "tree";
    cout << "Sort Characters By Frequency : " << s.frequencySort(str) << endl;
    return 0;
}