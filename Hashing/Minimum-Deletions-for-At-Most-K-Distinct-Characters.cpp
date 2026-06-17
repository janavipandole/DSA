#include <iostream>
#include <map>
using namespace std;

class Solution
{
public:
    int minDeletion(string s, int k)
    {
        map<char, int> mpp;

        for (auto ch : s)mpp[ch]++;
        
        if (mpp.size() - k <= 0)return 0;

        vector<int> hash;
        for (auto &[key, val] : mpp)hash.push_back(val);

        sort(hash.begin(), hash.end());

        int remove = mpp.size() - k;
        int ans = 0;

        for (int i = 0; i < remove; i++) ans += hash[i];

        return ans;
    }
};
int main()
{
    Solution s;
    string str = "abc";
    int k = 2;
    cout << "Minimum Deletions for At Most K Distinct Characters : " << s.minDeletion(str, k)<< endl;

    return 0;
}