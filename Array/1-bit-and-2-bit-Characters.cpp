#include <iostream>
using namespace std;

bool isOneBitCharacter(vector<int> &bits)
{
    vector<pair<int, int>> p;
    for (int i = 0; i < bits.size(); i++)
    {
        if (bits[i] == 1 && bits[i + 1] == 0)
        {
            p.push_back({bits[i], bits[i + 1]});
            i++;
        }
        else if (bits[i] == 1 && bits[i + 1] == 1)
        {
            p.push_back({bits[i], bits[i + 1]});
            i++;
        }
        else
        {
            p.push_back({bits[i], -1});
        }
    }
    if(p[p.size()-1].second == -1)return true;
    return false;
}

int main()
{
    vector<int> bits = {1, 0, 0};
    cout << "1-bit and 2-bit Characters : " << isOneBitCharacter(bits) << endl;
    
    return 0;
}