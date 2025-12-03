#include <iostream>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    vector<string> topKFrequentBrute(vector<string> &words, int k)
    {
        unordered_map<string, int> mpp;

        for (auto word : words) mpp[word]++;

        auto cmp = [](const pair<string, int> &a, const pair<string, int> &b)
        {
            if (a.second == b.second) return a.first < b.first; // pop lexicographically larger
            return a.second > b.second;   // pop higher frequency
        };

        priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(cmp)> minHeap(cmp);

        for (auto data : mpp)
        {
            minHeap.push({data.first, data.second});
            if (minHeap.size() > k) minHeap.pop();
        }

        vector<string> ans;
        while (minHeap.size() > 0)
        {
            ans.push_back(minHeap.top().first);
            minHeap.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

    vector<string> topKFrequentOptimal(vector<string>& words, int k) {
        unordered_map<string, int> map;
        for (int i = 0; i < words.size(); i++) {
            map[words[i]]++;
        }

        vector<pair<string, int>> vec(map.begin(), map.end());

        sort(vec.begin(), vec.end(), [](const auto& a, const auto& b) {
            if (a.second != b.second) return a.second > b.second;
            return a.first < b.first;
        });

        vector<string> ans;
        for (int i = 0; i < vec.size() && i < k; i++) {
            ans.push_back(vec[i].first);
        }
        return ans;
    }
};
int main()
{
    Solution s;
    vector<string> words = {"the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"};
    int k = 4;
    cout << "Top K Frequent Words :" << endl;
    vector<string> ans = s.topKFrequentOptimal(words, k);
    for (auto word : ans)
    {
        cout << word << ", ";
    }
    cout << endl;
    return 0;
}