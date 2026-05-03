#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_set<string> st;
        queue<pair<string, int>> q;

        for (auto word : wordList)
        {
            st.insert(word);
        }
        q.push({beginWord, 1});
        st.erase(beginWord);

        while (!q.empty())
        {
            auto word = q.front().first;
            int count = q.front().second;
            q.pop();

            if (word == endWord)
            {
                return count;
            }
            for (int i = 0; i < word.size(); i++)
            {
                char original = word[i];

                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    word[i] = ch;
                    if (st.count(word))
                    {
                        st.erase(word);
                        q.push({word, count + 1});
                    }
                }
                word[i] = original;
            }
        }
        return 0;
    }
};

int main()
{
    Solution s;
    string beginWord = "hit", endWord = "cog";
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};

    cout << "Word Ladder I : " << s.ladderLength(beginWord, endWord, wordList) << endl;
    return 0;
}