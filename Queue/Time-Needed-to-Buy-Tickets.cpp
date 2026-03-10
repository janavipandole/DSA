#include <iostream>
#include <queue>
using namespace std;
class Solution
{
public:
    int timeRequiredToBuy(vector<int> &tickets, int k)
    {
        queue<pair<int, int>> counter;
        for (int i = 0; i < tickets.size(); i++)
        {
            if (k == i) counter.push({tickets[i], -1});
            else counter.push({tickets[i], 0});
        }
        int time = 0;
        while(true){
            time += 1;
            pair<int, int> num = counter.front();
            counter.pop();
            num.first = num.first - 1;
            if(num.first == 0 && num.second == -1) return time;
            else if(num.first != 0 ) counter.push(num);
        }
        return time;
    }
};
int main()
{
    Solution s;
    vector<int> tickets = {5,1,1,1};
    int k = 0;
    cout << "Time Needed to Buy Tickets : "<<s.timeRequiredToBuy(tickets,k) << endl;
    return 0;
}