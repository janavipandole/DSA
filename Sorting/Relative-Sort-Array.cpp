#include <iostream>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2)
    {
        vector<int> ans;
        unordered_map<int, int> pos;
        for (int i = 0; i < arr2.size(); i++)
        {
            pos[arr2[i]] = i;
        }

        sort(arr1.begin(), arr1.end(), [&](int a, int b)
        {
            if (pos.count(a) && pos.count(b))
                return pos[a] < pos[b];
            if (pos.count(a))
                return true;
            if (pos.count(b))
                return false;
            return a < b; 
        });

        return arr1;
    }
};

int main()
{
    Solution s;
    vector<int> arr1 = {2, 3, 1, 3, 2, 4, 6, 7, 9, 2, 19}, arr2 = {2, 1, 4, 3, 9, 6};
    cout << "Relative Sort Array : " << endl;
    vector<int> ans = s.relativeSortArray(arr1, arr2);
    for (auto num : ans)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}