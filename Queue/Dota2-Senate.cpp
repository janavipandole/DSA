#include <iostream>
#include <queue>
using namespace std;

class Solution
{
public:
    string predictPartyVictory(string senate)
    {
        queue<int> Rqueue;
        queue<int> Dqueue;

        int n = senate.length();

        for (int i = 0; i < n; i++)
        {
            if (senate[i] == 'R')
            {
                Rqueue.push(i);
            }
            else
            {
                Dqueue.push(i);
            }
        }

        while (!Rqueue.empty() && !Dqueue.empty())
        {
            if (Rqueue.front() < Dqueue.front())
            {
                Dqueue.pop();
                int newIndex = Rqueue.front() + n;
                Rqueue.pop();
                Rqueue.push(newIndex);
            }
            else
            {
                Rqueue.pop();
                int newIndex = Dqueue.front() + n;
                Dqueue.pop();
                Dqueue.push(newIndex);
            }
        }
        return Rqueue.empty() ? "Dire" : "Radiant";
    }
};

int main()
{
    Solution s;
    string senate = "RD";
    cout << "Dota2 Senate : "<<s.predictPartyVictory(senate) << endl;

    return 0;
}