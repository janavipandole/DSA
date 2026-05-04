#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>
using namespace std;

class SolutionBruteForce
{
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_set<string> st(wordList.begin(), wordList.end());
        vector<vector<string>> result;
        queue<vector<string>> q;
        vector<string> usedOnLevel;
        int level = 0;

        q.push({beginWord});
        usedOnLevel.push_back(beginWord);

        while (!q.empty())
        {
            vector<string> vec = q.front();
            q.pop();

            // erase all the words that has been
            // used in the previous levels to trnsform
            if (vec.size() > level)
            {
                level++;
                for (auto it : usedOnLevel)
                {
                    st.erase(it);
                }
                usedOnLevel.clear();
            }

            string word = vec.back();
            if (word == endWord)
            {
                if (result.size() == 0)
                {
                    result.push_back(vec);
                }
                else if (result[0].size() == vec.size())
                {
                    result.push_back(vec);
                }
            }
            for (int i = 0; i < word.size(); i++)
            {
                char original = word[i];

                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    word[i] = ch;
                    if (st.count(word))
                    {
                        vec.push_back(word);
                        q.push(vec);
                        // marks ass visited at the level
                        usedOnLevel.push_back(word);
                        vec.pop_back();
                    }
                }
                word[i] = original;
            }
        }
        return result;
    }
};

class SolutionOptimal
{
private:
    unordered_map<string, int> ladderMap(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_set<string> st;
        queue<string> q;
        unordered_map<string, int> answer;

        for (auto word : wordList)
        {
            st.insert(word);
        }
        q.push(beginWord);
        st.erase(beginWord);
        answer[beginWord] = 1;

        while (!q.empty())
        {
            auto word = q.front();
            int step = answer[word];
            q.pop();

            if (word == endWord)
            {
                return answer;
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
                        answer[word] = step + 1;
                        q.push(word);
                    }
                }
                word[i] = original;
            }
        }
        return answer;
    }

    void DFS(string word, string beginWord, vector<string> vec, vector<vector<string>> &answer, unordered_map<string, int> mpp)
    {
        if (word == beginWord)
        {
            reverse(vec.begin(), vec.end());
            answer.push_back(vec);
            reverse(vec.begin(), vec.end());
            return;
        }
        int step = mpp[word];
        for (int i = 0; i < word.size(); i++)
        {
            char original = word[i];

            for (char ch = 'a'; ch <= 'z'; ch++)
            {
                word[i] = ch;
                if (mpp.count(word) && mpp[word] + 1 == step)
                {
                    vec.push_back(word);
                    DFS(word, beginWord, vec, answer, mpp);
                    vec.pop_back();
                }
            }
            word[i] = original;
        }
    }

public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_map<string, int> mpp = ladderMap(beginWord, endWord, wordList);
        vector<vector<string>> answer;

        if (mpp.find(endWord) != mpp.end())
        {
            vector<string> vec;
            vec.push_back(endWord);
            DFS(endWord, beginWord, vec, answer, mpp);
        }
        return answer;
    }
};

int main()
{
    SolutionOptimal s;
    string beginWord = "hit", endWord = "cog";
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};

    cout << "Word Ladder II : " << endl;
    vector<vector<string>> result = s.findLadders(beginWord, endWord, wordList);
    for (auto words : result)
    {
        for (auto word : words)
        {
            cout << word << " ";
        }
        cout << endl;
    }
    return 0;
}