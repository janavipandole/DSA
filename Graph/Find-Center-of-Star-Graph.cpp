#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int findCenter(vector<vector<int>> &edges)
    {
        int n = edges.size() + 2;
        vector<int> graph(n, 0);

        for (auto edge : edges)
        {
            graph[edge[0]]++;
            graph[edge[1]]++;
        }
        for (int i = 0; i < n; i++)
        {
            if (graph[i] == n - 2) return i;
        }
        return 0;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> edges = {{1, 2}, {2, 3}, {4, 2}};
    cout << "Find Center of Star Graph : " << s.findCenter(edges) << endl;
    return 0;
}