#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void DFS(vector<int> adjList[], vector<int> &visited, int index)
    {
        visited[index] = 1;

        for (auto it : adjList[index])
        {
            if (!visited[it])
            {
                DFS(adjList, visited, it);
            }
        }
    }
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int count = 0;
        int n = isConnected.size();
        vector<int> visited(n + 1, 0);
        vector<int> adjList[n];

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < isConnected[i].size(); j++)
            {
                if (isConnected[i][j] == 1 && i != j)
                {
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                count++;
                DFS(adjList, visited, i);
            }
        }
        return count;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> isConnected = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
    cout << "Number of Provinces : " << s.findCircleNum(isConnected) << endl;

    return 0;
}