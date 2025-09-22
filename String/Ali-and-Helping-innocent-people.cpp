#include <iostream>
using namespace std;
bool vowel(char ch)
{
    return ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U' || ch == 'Y';
}
int main()
{
    cout << "Ali and Helping innocent people : " << endl;
    string tag;
    cin >> tag;

    if ((tag[0] - '0' + tag[1] - '0') % 2 == 1 ||
        (tag[3] - '0' + tag[4] - '0') % 2 == 1 ||
        (tag[4] - '0' + tag[5] - '0') % 2 == 1 ||
        (tag[7] - '0' + tag[8] - '0') % 2 == 1)
    {
        cout << "invalid" << endl;
    }
    else if (vowel(tag[2]))
        cout << "invalid" << endl;
    else
        cout << "valid" << endl;
    return 0;
}