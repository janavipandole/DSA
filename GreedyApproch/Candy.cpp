#include <iostream>
using namespace std;
class Solution
{
public:
    int candy_1(vector<int> &ratings)
    {
        int n = ratings.size();
        int sum = 0;
        vector<int> left(n, 1), right(n, 1);

        for (int i = 1; i < n; i++)
        {
            if (ratings[i] > ratings[i - 1])
            {
                left[i] = left[i - 1] + 1;
            }
           
        }

        for (int i = n - 2; i >= 0; i--)
        {
            if (ratings[i] > ratings[i + 1])
            {
                right[i] = right[i + 1] + 1;
            }
        }

        for (int i = 0; i < n; i++)
        {
            sum += max(right[i], left[i]);
        }
        return sum;
    }

    int candy_2(vector<int> &ratings)
    {
        int n = ratings.size();
        int sum = 0, right = 1;
        vector<int> left(n, 1);

        for (int i = 1; i < n; i++)
        {
            if (ratings[i] > ratings[i - 1])
            {
                left[i] = left[i - 1] + 1;
            }
        }
        sum = left[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            if (ratings[i] > ratings[i + 1])
            {
                right++;
            }
            else
            {
                right = 1;
            }
            sum += max(left[i], right);
        }

        return sum;
    }

    int candy_3(vector<int> &ratings)
    {
        int n = ratings.size();
        int sum = 1;
        int i = 1;
        while(i < n){
            if(ratings[i] == ratings[i-1]) {
                sum += 1;
                i++;
                continue;;
            }
            int peak = 1;
            while(i < n && ratings[i] > ratings[i-1]){
                peak++;
                sum += peak;
                i++;
            }

            int down = 0;
            while(i < n && ratings[i] < ratings[i-1]){
                down++;
                sum += down;
                i++;
            }
            down++;
            if(down > peak) sum += (down - peak);
        }
        return sum;
    }
};
int main()
{
    Solution s;
    vector<int> ratings = {1, 3, 2, 2, 1};
    cout << "Candy : " << s.candy_1(ratings) << endl;
    cout << "Candy : " << s.candy_2(ratings) << endl;
    cout << "Candy : " << s.candy_3(ratings) << endl;

    return 0;
}