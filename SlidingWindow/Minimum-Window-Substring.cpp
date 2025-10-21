#include <iostream>
using namespace std;
class Solution
{
public:
    string minWindow_Brute(string s, string t)
    {
        if(t.size() > s.size()) return "";
        int minLen = INT_MAX;
        int sIndex = -1;
        for (int i = 0; i < s.size(); i++)
        {
            int hash[256] = {0};
            int cnt = 0;
            for (auto ch : t)
            {
                hash[ch]++;
            }
            for (int j = i; j < s.size(); j++)
            {
                if(hash[s[j]] > 0) cnt += 1;
                hash[s[j]]--;

                if(cnt == t.size()){
                    if(j - i + 1 < minLen){
                        minLen = j - i + 1;
                        sIndex = i;
                        break;
                    }
                }
            }
        }
        return s.substr(sIndex, minLen);
    }

    string minWindow_Optimal(string s, string t) {
        if(t.size() > s.size()) return "";
        int hash[256] = {0};
        int l = 0, r = 0, cnt = 0;
        int minLen = INT_MAX, sIndex = -1;

        for (auto ch : t) hash[ch]++;

        while(r < s.size())
        {
            if(hash[s[r]] > 0) cnt += 1;
            hash[s[r]]--;

            while(cnt == t.size()){
                if(r - l + 1 < minLen){
                    minLen = r - l + 1;
                    sIndex = l;    
                }
                hash[s[l]]++;
                if (hash[s[l]] > 0) cnt--;
                l++;
            }
            r += 1;
        }
        return sIndex == -1 ? "" : s.substr(sIndex, minLen); 
    }
};
int main()
{
    Solution Sol;
    string s = "ADOBECODEBANC", t = "ABC";
    cout<<"Minimum Window Substring : "<<Sol.minWindow_Brute(s,t)<<endl;
    cout<<"Minimum Window Substring : "<<Sol.minWindow_Optimal(s,t)<<endl;

    return 0;
}