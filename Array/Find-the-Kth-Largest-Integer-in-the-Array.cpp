#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution
{
public:
    struct Compare
    {
        bool operator()(string &a, string &b)
        {
            if (a.length() == b.length())
                return a > b;
            return a.length() > b.length();
        }
    };
    string kthLargestNumber(vector<string> &nums, int k)
    {
        priority_queue<string, vector<string>, Compare> minHeap;
        for (int i = 0; i < nums.size(); i++)
        {
            minHeap.push(nums[i]);
            if (minHeap.size() > k)
            {
                minHeap.pop();
            }
        }
        string ans = minHeap.top();
        return ans;
    }
};
int main()
{
    Solution s;
    vector<string> nums = {"623986800", "3", "887298", "695", "794", "6888794705", "269409", "59930972", "723091307", "726368", "8028385786", "378585"};
    int k = 11;
    cout << "Find the Kth Largest Integer in the Array : " << s.kthLargestNumber(nums, k) << endl;
    return 0;
}