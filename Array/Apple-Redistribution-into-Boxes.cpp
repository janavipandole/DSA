#include <iostream>
using namespace std;
class Solution
{
public:
    int minimumBoxes(vector<int> &apple, vector<int> &capacity)
    {
        sort(capacity.rbegin(), capacity.rend());
        int sum = 0, cnt = 0;
        for (auto a : apple)
            sum += a;

        for (auto c : capacity)
        {
            if (sum <= 0)
                return cnt;
            cnt++;
            sum -= c;
        }
        return cnt;
    }
};
int main()
{
    Solution s;
    vector<int> apple = {1,3,2}, capacity = {4,3,1,5,2};
    cout<<"Apple Redistribution into Boxes : "<< s.minimumBoxes(apple, capacity) << endl;
    return 0;
}