#include <iostream>
#include <math.h>
using namespace std;

class Solution
{
public:
    int maxContainers(int n, int w, int maxWeight)
    {
        int num = min(n * n, maxWeight / w);
        return num;
    }
};
int main()
{
    Solution s;
    int n = 2, w = 3, maxWeight = 15;
    cout << "Maximum Containers on a Ship : " << s.maxContainers(n, w, maxWeight) << endl;
    return 0;
}