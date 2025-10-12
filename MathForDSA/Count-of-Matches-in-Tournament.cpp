#include <iostream>
using namespace std;
class Solution
{
public:
    int numberOfMatches(int n)
    {
        return n-1;
    }
};
int main()
{
    Solution s;
    int n = 7;
    cout << " Count of Matches in Tournament : " << s.numberOfMatches(n) << endl;
    return 0;
}