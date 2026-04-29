#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int findChampion(int n, vector<vector<int>> &edges)
    {
        vector<int> inDegree(n, 0);

        for (auto edge : edges)
        {
            inDegree[edge[1]]++;
        }

        int champion = -1;
        int count = 0;
        for (auto deg : inDegree)
        {
            if(deg == 0){
                champion = deg;
                count++;
            }
        }
        if(count > 1) return -1;
        return champion;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> edges = {{0, 1}, {1, 2}};
    int n = 3;
    cout << "Find Champain II : " << s.findChampion(n, edges) << endl;
    return 0;
}