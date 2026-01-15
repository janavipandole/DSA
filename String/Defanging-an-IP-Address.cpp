#include <iostream>
using namespace std;

class Solution
{
public:
    string defangIPaddr(string address)
    {
        string ans;
        for (int i = 0; i < address.size(); i++)
        {
            if (address[i] == '.')
            {
                ans += "[.]";
            }
            else
            {
                ans += address[i];
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    string address = "1.1.1.1";
    cout << "Defanging an IP Address : " << s.defangIPaddr(address) << endl;

    return 0;
}