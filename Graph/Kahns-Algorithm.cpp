#include <iostream>
#include <queue>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> topoSort(int V, vector<vector<int>> &edges)
    {
        vector<int> ans;
        vector<int> adjList[V];
        queue<int> q;
        vector<int> inDegree(V, 0);

        for (auto edge : edges)
        {
            adjList[edge[0]].push_back(edge[1]);
        }

        for (int i = 0; i < V; i++)
        {
            for (auto edge : adjList[i])
            {
                inDegree[edge]++;
            }
        }

        for (int i = 0; i < V; i++)
        {
            if (inDegree[i] == 0)
            {
                q.push(i);
            }
        }

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for (auto it : adjList[node])
            {
                inDegree[it]--;
                if (inDegree[it] == 0)
                {
                    q.push(it);
                }
            }
        }
        return ans;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> edges = {{3, 0}, {1, 0}, {2, 0}};
    int V = 4;
    cout << "Kahn's Algorithm : " << endl;

    vector<int> ans = s.topoSort(V, edges);
    for (auto num : ans)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}