#include <iostream>
using namespace std;
class Solution
{
public:
    int convertTime_Brute(string current, string correct)
    {
        int currentInMin = stoi(current);
        int correctInMin = stoi(correct);

        int minCurrent = 0, minCorrect = 0;

        for (int i = 3; i < current.size(); i++)
        {
            minCurrent = minCurrent * 10 + current[i] - '0';
            minCorrect = minCorrect * 10 + correct[i] - '0';
        }
        currentInMin *= 60;
        correctInMin *= 60;
        currentInMin += minCurrent;
        correctInMin += minCorrect;
        correctInMin -= currentInMin;

        int cnt = 0;
        while (correctInMin > 0)
        {
            if (correctInMin >= 60)
            {
                cnt++;
                correctInMin -= 60;
            }
            else if (correctInMin >= 15)
            {
                cnt++;
                correctInMin -= 15;
            }
            else if (correctInMin >= 5)
            {
                cnt++;
                correctInMin -= 5;
            }
            else
            {
                cnt++;
                correctInMin -= 1;
            }
        }
        return cnt;
    }
    int convertTime_optimal(string current, string correct)
    {
        int current_hour = stoi(current.substr(0, 2));
        int correct_hour = stoi(correct.substr(0, 2));
        int current_min = stoi(current.substr(3, 2));
        int correct_min = stoi(correct.substr(3, 2));

        int current_total = current_hour * 60 + current_min;
        int correct_total = correct_hour * 60 + correct_min;

        int diff = correct_total - current_total;
        vector<int> nums = {60, 15, 5, 1};
        int cnt = 0;
        for (auto num : nums)
        {
            cnt += diff / num;
            diff %= num;
        }
        return cnt;
    }
};
int main()
{
    Solution s;
    string current = "02:30", correct = "04:35";
    cout << "Minimum Number of Operations to Convert Time : " << s.convertTime_Brute(current, correct) << endl;
    cout << "Minimum Number of Operations to Convert Time : " << s.convertTime_optimal(current, correct) << endl;

    return 0;
}