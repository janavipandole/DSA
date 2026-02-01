#include <iostream>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    string kthDistinct(vector<string> &arr, int k)
    {
        unordered_map<string, int> hash;
        for (auto str : arr)
        {
            hash[str]++;
        }
        int count = 0;
        for (auto str : arr)
        {
            if (hash[str] == 1)
            {
                count++;
                if (count == k)
                {
                    return str;
                }
            }
        }

        return "";
    }
};
int main()
{
    Solution s;
    vector<string> strs = {"d", "b", "c", "b", "c", "a"};
    cout << "Kth Distinct String in an Array : " << s.kthDistinct(strs, 2) << endl;
    return 0;
}