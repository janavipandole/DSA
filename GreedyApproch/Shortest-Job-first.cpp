#include <iostream>
using namespace std;
class Solution
{
public:
    long long solve(vector<int> &bt)
    {
        sort(bt.begin(), bt.end());
        long long waiting_time = 0, time = 0;
    
        for (int i = 0; i < bt.size(); i++)
        {
            waiting_time += time;
            time += bt[i];
        }

        waiting_time = waiting_time / bt.size();

        return waiting_time;
    }
};
int main()
{
    Solution s;
    vector<int> bt = {1,2,3,4,7};
    cout << "Shortest Job first : " << s.solve(bt) << endl;
    return 0;
}