#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int countSeniors(vector<string> &details)
    {
        int count = 0;
        for (int i = 0; i < details.size(); i++)
        {

            if (details[i][11] > '6' || (details[i][11] == '6' && details[i][12] != '0'))
            {

                count++;
            }
        }
        return count;
    }
};

int main()
{
    Solution s;
    vector<string> details = {"5612624052M0130", "5378802576M6424", "5447619845F0171", "2941701174O9078"};
    cout << "Number of Senior Citizens : " << s.countSeniors(details) << endl;
    return 0;
}