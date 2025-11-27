#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    double gain(int p, int t)
    {
        return (double)(p + 1) / (t + 1) - (double)p / t;
    }

    double maxAverageRatio(vector<vector<int>> &classes, int extraStudents)
    {
        priority_queue<pair<double, pair<int, int>>> maxHeap;

        for (auto &c : classes)
        {
            int p = c[0], t = c[1];
            maxHeap.push({gain(p, t), {p, t}});
        }

        while (extraStudents--)
        {
            auto top = maxHeap.top();
            maxHeap.pop();

            int p = top.second.first;
            int t = top.second.second;

            p++;
            t++;

            maxHeap.push({gain(p, t), {p, t}});
        }

        double ans = 0.0;
        while (!maxHeap.empty())
        {
            auto top = maxHeap.top();
            maxHeap.pop();
            int p = top.second.first;
            int t = top.second.second;
            ans += (double)p / t;
        }

        return ans / classes.size();
    }
};

int main()
{
    Solution s;
    vector<vector<int>> classes = {{1, 2}, {3, 5}, {2, 2}};
    int extraStudents = 2;
    cout << "Maximum Average Pass Ratio : "
         << s.maxAverageRatio(classes, extraStudents) << endl;
    return 0;
}
