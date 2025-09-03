#include <iostream>
using namespace std;
// Brute force solution
char nextGreatestLetterBrute(vector<char> &letters, char target)
{
    int low = 0;
    int high = letters.size() - 1;
    int ans = letters[0];
    for (int i = low; i <= high; i++)
    {
        if (letters[i] > target)
        {
            return letters[i];
        }
    }
    return ans;
}

// Optimal solution
char nextGreatestLetterOptimal(vector<char> &letters, char target)
{
    int low = 0;
    int high = letters.size() - 1;
    int ans = letters[0];
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (letters[mid] > target)
        {
            ans = letters[mid];
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}
int main()
{
    vector<char> letters = {'c', 'f', 'j'};
    char target = 'c';
    cout << "nextGreatestLetter : " << nextGreatestLetterBrute(letters, target) << endl;
    cout << "nextGreatestLetter : " << nextGreatestLetterOptimal(letters, target) << endl;
    return 0;
}