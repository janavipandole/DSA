#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
    {
        int count = 0;
        vector<int> adjList[numCourses];
        queue<int> q;
        vector<int> inDegree(numCourses, 0);

        for (auto prerequisite : prerequisites)
        {
            adjList[prerequisite[0]].push_back(prerequisite[1]);
        }

        for (int i = 0; i < numCourses; i++)
        {
            for (auto edge : adjList[i]) inDegree[edge]++;
        }

        for (int i = 0; i < numCourses; i++)
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
                if (inDegree[it] == 0) q.push(it);
            }
        }
        if (count == numCourses) return false;
        return true;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> edges = {{1, 0}, {0, 1}};
    int V = 2;
    cout << "Course Schedule I : " << s.canFinish(V, edges) << endl;

    return 0;
}