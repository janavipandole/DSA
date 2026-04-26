#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        int count = 0;
        vector<int> adjList[V];
        queue<int> q;
        vector<int> inDegree(V, 0);

        for (auto edge : edges)
        {
            adjList[edge[0]].push_back(edge[1]);
        }

        for (int i = 0; i < V; i++)
        {
            for (auto edge : adjList[i]) inDegree[edge]++;
        }

        for (int i = 0; i < V; i++)
        {
            if (inDegree[i] == 0) q.push(i);
        }

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            count++;

            for (auto it : adjList[node])
            {
                inDegree[it]--;
                if (inDegree[it] == 0)q.push(it);
            }
        }
        if(count == V) return false;
        return true;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> edges = {{3, 0}, {1, 0}, {2, 0}};
    int V = 4;
    cout << "Detect a Cycle in Directed Graph using BFS : " << s.isCyclic(V, edges) << endl;

    return 0;
}