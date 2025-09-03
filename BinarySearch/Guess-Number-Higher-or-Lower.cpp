#include <iostream>
using namespace std;
/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */
int guess(int num)
{
    int n = 6;

    if(n == num) return 0;
    else if(n < num) return -1;
    else return 1;
}
// Brute force solution
int guessNumberBrute(int n)
{
    int low = 1, high = n;
    for(int i = low; i <= high; i++){
        if (guess(i) == 0) return i;
    }
    return -1;
}
// Optimal solution
int guessNumberOptimal(int n)
{
    int low = 1, high = n;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (guess(mid) == 0) return mid;
        if (guess(mid) == -1) high = mid - 1;
        else low = mid + 1;
    }
    return -1;
}

int main()
{
    cout << "guessNumber : " << guessNumberBrute(10) << endl;
    cout << "guessNumber : " << guessNumberOptimal(10) << endl;
    return 0;
}
