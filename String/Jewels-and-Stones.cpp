#include <iostream>
using namespace std;

int numJewelsInStones(string jewels, string stones)
{
    unordered_map<char, bool> mpp;
    int result = 0;
    for (auto jewel : jewels)
    {
        mpp[jewel] = true;
    }

    for(auto stone : stones){
        if(mpp.find(stone) != mpp.end()) result += 1;
    }
    return result;
}
int main()
{
    string jewels = "aA", stones = "aAAbbbb";
    return 0;
}