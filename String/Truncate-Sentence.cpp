#include <iostream>
using namespace std;

class Solution {
public:
    string truncateSentence(string s, int k) {
       string ans;

       for(int i = 0; i<s.size();i++){
        string word;
        while(i < s.size() && s[i] != ' '){
            word += s[i];
            i++;
        }
        if(k > 0){
            ans += word;
            k--; 
            if(k == 0) break;
            ans += ' ';
            
        }
       } 
       return ans;
    }
};

int main()
{
    Solution s;
    string str = "Hello how are you Contestant";
    int k = 4;
    cout<<"Truncate Sentence : "<<s.truncateSentence(str, k)<<endl;
    return 0;
}