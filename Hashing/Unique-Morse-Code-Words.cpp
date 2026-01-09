#include <iostream>
#include <unordered_map>
#include<unordered_set>
using namespace std;

class Solution
{
public:
    string value(char c)
    {
        if (c == 'a') return ".-";
        if (c == 'b') return "-...";
        if (c == 'c') return "-.-.";
        if (c == 'd') return "-..";
        if (c == 'e') return ".";
        if (c == 'f') return "..-.";
        if (c == 'g') return "--.";
        if (c == 'h') return "....";
        if (c == 'i') return "..";
        if (c == 'j') return ".---";
        if (c == 'k') return "-.-";
        if (c == 'l') return ".-..";
        if (c == 'm') return "--";
        if (c == 'n') return "-.";
        if (c == 'o') return "---";
        if (c == 'p') return ".--.";
        if (c == 'q') return "--.-";
        if (c == 'r') return ".-.";
        if (c == 's') return "...";
        if (c == 't') return "-";
        if (c == 'u') return "..-";
        if (c == 'v') return "...-";
        if (c == 'w') return ".--";
        if (c == 'x') return "-..-";
        if (c == 'y') return "-.--";
        return "--.."; 
    }
    int uniqueMorseRepresentations(vector<string> &words)
    {
        unordered_set<string> hash;
        for(int i = 0; i < words.size(); i++)
        {
            string word;
            for(int  j = 0; j < words[i].size(); j++)
            {
                word += value(words[i][j]);
            }
            
            hash.insert(word);
        }
       
        return hash.size();
    }
};
int main()
{
    Solution s;
    vector<string> words = {"gin", "zen", "gig", "msg"};
    cout << "Unique Morse Code Words : " << s.uniqueMorseRepresentations(words) << endl;
    return 0;
}