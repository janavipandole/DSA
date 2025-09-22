#include <iostream>
using namespace std;
bool isUpper(char ch)
{
    if (ch >= 'A' && ch <= 'Z')return true;
    return false;
}
int main()
{
    string s = "abcdE";
    for(auto &ch : s){
        if(isUpper(ch)) ch = tolower(ch);
        else ch = toupper(ch);
    }
    cout<<s<<endl;
    return 0;
}