#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<int> answer;
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
            answer.push_back(node);

            for (auto it : adjList[node])
            {
                inDegree[it]--;
                if (inDegree[it] == 0) q.push(it);
            }
        }
        if (answer.size() != numCourses) return {};
        int i = 0;
        int j = numCourses - 1;

        while(i<j){
            swap(answer[i],answer[j]);
            i++;
            j--;
        }

        return answer;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> edges = {{1, 0}};
    int V = 2;
    cout << "Course Schedule II : " << endl;
    vector<int> answer = s.findOrder(V, edges);
    for (auto ans : answer)
    {
        cout << ans << " ";
    }
    cout << endl;

    return 0;
}