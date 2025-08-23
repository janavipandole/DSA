#include <iostream>
using namespace std;

int myAtoi(string &s)
{
    int i = 0, n = s.length();
    long result = 0; // Use long to detect overflow before clamping
    int sign = 1;

    // Step 1: Skip leading whitespace
    while (i < n && s[i] == ' ')
    {
        i++;
    }

    // Step 2: Check for sign (s[i] == '+' || s[i] == '-') this check is important for +1 test case
    if (i < n && (s[i] == '+' || s[i] == '-'))
    {
        sign = (s[i] == '-') ? -1 : 1;
        i++;
    }

    // Step 3: Read digits and build the number
    while (i < n && isdigit(s[i]))
    {
        int digit = s[i] - '0';

        result = result * 10 + digit;

        // Step 4: Clamp if out of 32-bit signed int range
        if (sign * result <= INT_MIN)
            return INT_MIN;
        if (sign * result >= INT_MAX)
            return INT_MAX;

        i++;
    }

    // Step 5: Apply sign and return
    return (sign * result);
}

int main()
{
    string s = "  -1337c0d3";
    cout << myAtoi(s) << endl;
    return 0;
}