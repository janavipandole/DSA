#include <iostream>
#include <unordered_map>
using namespace std;
vector<int> recoverOrder(vector<int> &order, vector<int> &friends)
{
    unordered_map<int, int> mpp;
    for (int i = 0; i < friends.size(); i++)
    {
        mpp[friends[i]] = i;
    }
    vector<int> ans;

    for (int i = 0; i < order.size(); i++)
    {
        if (mpp.find(order[i]) != mpp.end())
        {
            ans.push_back(order[i]);
        }
    }
    return ans;
}
int main()
{
    vector<int> order = {3, 1, 2, 5, 4};
    vector<int> friends = {1, 3, 4};
    cout << "Restore Finishing Order : " << endl;
    vector<int> ans = recoverOrder(order, friends);
    for (auto num : ans)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}