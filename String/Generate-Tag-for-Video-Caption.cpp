#include <iostream>
using namespace std;

string generateTag(string caption)
{
    string tag = "#";
    string word;
    bool isFirstWord = true;

    for (char ch : caption)
    {
        if (isalpha(ch)) word += ch;
        else if (!word.empty())
        {
            if (isFirstWord)
            {
                for (char &c : word)
                c = tolower(c);
                isFirstWord = false;
            }
            else
            {
                word[0] = toupper(word[0]);
                for (int i = 1; i < word.size(); i++) word[i] = tolower(word[i]);
            }
            tag += word;
            word.clear();
        }
    }
    if (!word.empty())
    {
        if (isFirstWord)
        {
            for (char &c : word) c = tolower(c);
        }
        else
        {
            word[0] = toupper(word[0]);
            for (int i = 1; i < word.size(); i++) word[i] = tolower(word[i]);
        }
        tag += word;
    }

    if (tag.size() > 100) tag = tag.substr(0, 100);

    return tag;
}
int main()
{
    string caption = " fPysaRtLQLiMKVvRhMkkDLNedQKffPnCjbITBTOVhoVjiKbfSawvpisDaNzXJctQkn";
    cout << "Generate Tag for Video Caption : " << generateTag(caption) << endl;
    return 0;
}