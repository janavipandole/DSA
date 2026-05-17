#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    bool isValid(int source, int destination, vector<int> adjList[], vector<int> &visited)
    {
        if (source == destination)
        {
            return true;
        }
        visited[source] = 1;

        for (auto it : adjList[source])
        {
            if (visited[it] == 0)
            {
                if (isValid(it, destination, adjList, visited))
                {
                    return true;
                }
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
    {
        if (source == destination)
        {
            return true;
        }

        vector<int> adjList[n];
        vector<int> visited(n, 0);

        for (auto edge : edges)
        {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }
       
        return isValid(source, destination, adjList, visited);
    }
};
int main()
{
    Solution s;
    int n = 3, source = 0, destination = 2;
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 0}};
    cout << "Find if Path Exists in Graph : " << s.validPath(n, edges, source, destination) << endl;
    return 0;
}