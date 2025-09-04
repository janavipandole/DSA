#include <iostream>
using namespace std;
pair<int, int> get(int a, int b)
{
    return {b, a};
}
pair<int, int> getSwapByXOR(int a, int b)
{
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    return {a, b};
}
int main()
{
    int a = 13, b = 9;
    pair<int, int> ans = getSwapByXOR(a, b);
    cout << "Get number : " << ans.first << " " << ans.second << endl;
    return 0;
}