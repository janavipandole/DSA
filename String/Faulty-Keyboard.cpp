#include <iostream>
using namespace std;
class Solution {
public:
    string finalString(string s) {
        string ans;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == 'i') reverse(ans.begin(),ans.end());
            else ans += s[i];
        }
        return ans;
    }
};
int main()
{
    Solution s;
    string strs ="string";
    cout << "Faulty Keyboard : " << s.finalString(strs) << endl;
    return 0;
}