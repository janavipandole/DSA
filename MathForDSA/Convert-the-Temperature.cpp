#include <iostream>
using namespace std;
class Solution
{
public:
    vector<double> convertTemperature(double celsius)
    {
        double Kelvin = celsius + 273.15;
        double Fahrenheit = celsius * 1.80 + 32.00;
        return {Kelvin, Fahrenheit};
    }
};
int main()
{
    Solution s;
    double celsius = 36.50;
    vector<double> ans = s.convertTemperature(celsius);
    cout << "Convert the Temperature : " << endl
         << "Kelvin : " << ans[0] << endl
         << "Fahrenheit : " << ans[1] << endl;
    ;
    return 0;
}