#include <iostream>
using namespace std;
class Solution
{
public:
    int findClosest(int x, int y, int z)
    {
        int first = abs(x - z);
        int second = abs(y - z);
        if (first < second) return 1;
        if (first > second) return 2;
        return 0;
    }
};
int main()
{
    Solution s;
    int  x = 2, y = 7, z = 4; 
    cout<<"Find Closest Person : "<<s.findClosest(x,y,z)<<endl;
    return 0;
}