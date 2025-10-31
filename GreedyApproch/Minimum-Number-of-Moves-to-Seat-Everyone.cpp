#include <iostream>
using namespace std;
class Solution
{
public:
    int minMovesToSeat(vector<int> &seats, vector<int> &students)
    {
        int n = seats.size(), sum = 0;
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());

        for(int i=0;i<seats.size();i++){
            sum = sum + abs(students[i] - seats[i]);
        }
        return sum; 
    }
};
int main()
{
    Solution s;
    vector<int> seats = {3, 1, 5}, students = {2, 7, 4};
    cout << "Minimum Number of Moves to Seat Everyone : " << s.minMovesToSeat(seats, students) << endl;
    return 0;
}