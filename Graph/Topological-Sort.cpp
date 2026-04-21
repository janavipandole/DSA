#include <iostream>
using namespace std;

class Solution
{
public:
    void DFS(vector<int> &visited, vector<int> adjList[], stack<int> &st, int node)
    {
        visited[node] = 1;

        for (auto it : adjList[node])
        {
            if (!visited[it])
            {
                DFS(visited, adjList, st, it);
            }
        }
        st.push(node);
    }
    vector<int> topoSort(int V, vector<vector<int>> &edges)
    {
        vector<int> visited(V, 0);
        vector<int> adjList[V];
        stack<int> st;

        for (auto edge : edges)
        {
            adjList[edge[0]].push_back(edge[1]);
        }

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                DFS(visited, adjList, st, i);
            }
        }

        vector<int> answer;
        while (!st.empty())
        {
            answer.push_back(st.top());
            st.pop();
        }
        return answer;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> edges = {{3, 0}, {1, 0}, {2, 0}};
    int n = 4;
    cout << "Topological Sort : " << endl;
    vector<int> answer = s.topoSort(n, edges);
    for (auto ans : answer)
    {
        cout << ans << " ";
    }
    cout << endl;
    return 0;
}