#include <iostream>
#include <map>
using namespace std;

class Solution
{
public:
    string sortSentence(string s)
    {
        vector<string> arr(10); // since max 9 words
        string word = "";

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ' ')
            {
                int pos = word.back() - '0';
                word.pop_back();
                arr[pos] = word;
                word = "";
            }
            else
            {
                word += s[i];
            }
        }

        // last word
        int pos = word.back() - '0';
        word.pop_back();
        arr[pos] = word;

        string ans = "";
        for (int i = 1; i < 10; i++)
        {
            if (arr[i] != "")
            {
                if (!ans.empty())
                {
                    ans += " ";
                }
                ans += arr[i];
            }
        }

        return ans;
    }
};

int main()
{
    Solution s;
    string sentence = "is2 sentence4 This1 a3";
    cout << "Sorting the Sentence : " << s.sortSentence(sentence) << endl;

    return 0;
}