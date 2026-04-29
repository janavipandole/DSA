#include <iostream>
using namespace std;
class Solution
{
public:
    vector<int> findSmallestSetOfVertice1(int n, vector<vector<int>> &edges)
    {
        vector<int> answer;
        vector<int> adjList[n];
        vector<int> inDegree(n, 0);

        for (auto edge : edges)
        {
            adjList[edge[0]].push_back(edge[1]);
        }

        for (int i = 0; i < n; i++)
        {
            for (auto edge : adjList[i]) inDegree[edge]++;
        }

        for (int i = 0; i < n; i++)
        {
            if (inDegree[i] == 0) answer.push_back(i);
        }
        return answer;
    }
    vector<int> findSmallestSetOfVertices2(int n, vector<vector<int>>& edges) {
        vector<int> v(n, 0);

        for(const auto& it : edges){
            v[it[1]] = 1; 
        }

        vector<int> ans;
        for(int i = 0; i < n; i++){
            if(v[i] == 0) ans.push_back(i);
        }

        return ans;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {2, 5}, {3, 4}, {4, 2}};
    int n = 6;
    cout << "Minimum Number of Vertices to Reach All Nodes : " << endl;
    vector<int> answer = s.findSmallestSetOfVertices(n, edges);
    for (auto ans : answer)
    {
        cout << ans << " ";
    }
    cout << endl;
    return 0;
}
