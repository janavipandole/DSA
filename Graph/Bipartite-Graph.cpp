#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    bool DFS(vector<vector<int>> &graph, vector<int> &visited, int index, int color)
    {
        if(index >= graph.size()) return true;
        visited[index] = color;
    
        for (auto it : graph[index])
        {
            if (visited[it] == -1)
            {
                if(DFS(graph, visited, it, !color) == false) return false;
            }
            else if (visited[it] == color)return false;
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> visited(n + 1, -1);

        for (int i = 0; i < n; i++)
        {
            if (visited[i] == -1)
            {
                if (DFS(graph, visited, i, 0) == false)
                {
                    return false;
                }
            }
        }
        return true;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> graph = {{1, 2, 3}, {0, 2}, {0, 1, 3}, {0, 2}};
    cout << "Is Graph Bipartite? : " << s.isBipartite(graph) << endl;

    return 0;
}