#include <iostream>
using namespace std;
class Solution
{
public:
    int maxScore(vector<int> &cardPoints, int k)
    {
        int leftSum = 0, rightSum = 0, MaxSum = 0, n = cardPoints.size();
        for (int i = 0; i < k; i++)
        {
            leftSum += cardPoints[i];
        }
        MaxSum = leftSum;
        int rightIndex = n - 1;
        for (int i = k - 1; i >= 0; i--)
        {
            leftSum -= cardPoints[i];
            rightSum += cardPoints[rightIndex];
            rightIndex--;
            MaxSum = max(MaxSum, leftSum + rightSum);
        }
        return MaxSum;
    }
};
int main()
{
    Solution s;
    vector<int> cardPoints = {1, 2, 3, 4, 5, 6, 1};
    int k = 3;
    cout << "Maximum Points You Can Obtain from Cards : " << s.maxScore(cardPoints, k) << endl;
    return 0;
}