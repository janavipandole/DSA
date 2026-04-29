#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution
{
public:
    void DFS(int node, vector<int> &visited, vector<int> adjList[], vector<int> &degree, int &countNode, int &countEdege)
    {
        visited[node] = 1;
        countNode += 1;
        countEdege += degree[node];

        for (auto adj : adjList[node])
        {
            if (!visited[adj])
            {
                DFS(adj, visited, adjList, degree, countNode, countEdege);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>> &edges)
    {
        int countAsnwer = 0;
        vector<int> adjList[n];
        vector<int> visited(n, 0);
        vector<int> degree(n, 0);

        for (auto edge : edges)
        {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }

        for (int i = 0; i < n; i++)
        {
            for (auto edge : adjList[i])
            {
                degree[edge]++;
            }
        }

        for (int i = 0; i < n; i++)
        {
            int countNode = 0, countEdege = 0;
            if (!visited[i])
            {
                DFS(i, visited, adjList, degree, countNode, countEdege);
                if (countEdege == (countNode * (countNode - 1)))
                {
                    countAsnwer++;
                }
            }
        }
        return countAsnwer;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 2}, {3, 4}};
    int n = 6;
    cout << "Count the Number of Complete Components : " << s.countCompleteComponents(n, edges) << endl;

    return 0;
}