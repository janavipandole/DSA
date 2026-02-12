#include <iostream>
using namespace std;

class Solution
{
public:
    vector<string> splitWordsBySeparator(vector<string> &words, char separator)
    {
        vector<string> ans;

        for (int i = 0; i < words.size(); i++)
        {
            string word = "";
            for (int j = 0; j < words[i].size(); j++)
            {
                if (words[i][j] == separator)
                {
                    if (!word.empty())
                    {
                        ans.push_back(word);
                        word = "";
                    }
                }
                else
                {
                    word += words[i][j];
                }
            }
            if (!word.empty())
            {
                ans.push_back(word);
            }
        }
        return ans;
    }
};
int main()
{
    Solution s;
    vector<string> words = {"one.two.three", "four.five", "six"};
    char separator = '.';
    cout << "Split Strings by Separator : " << endl;
    vector<string> ans = s.splitWordsBySeparator(words, separator);
    for (auto word : ans)
    {
        cout << word << " ";
    }
    cout << endl;
    return 0;
}