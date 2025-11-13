#include <iostream>
using namespace std;
class Solution
{
public:
    vector<string> buildArray(vector<int> &target, int n)
    {
        vector<string> v;
        int x = 1;
        int i = 0;
        while (i < target.size() and x <= n)
        {
            v.push_back("Push");
            if (target[i] == x)
            {

                i++;
            }
            else
            {
                v.push_back("Pop");
            }
            x++;
        }
        return v;
    }
};
int main()
{
    Solution s;
    vector<int> target = {1, 3};
    int n = 3;
    cout << "Build an Array With Stack Operations : " << endl;
    vector<string> ans = s.buildArray(target, n);
    for (auto word : ans)
    {
        cout << word << " ";
    }
    cout << endl;
    return 0;
}