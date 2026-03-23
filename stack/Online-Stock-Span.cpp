#include <iostream>
#include <stack>
using namespace std;

class StockSpannerBetter
{
    vector<int> prices;

public:
    StockSpannerBetter()
    {
        prices.clear();
    }

    int next(int price)
    {
        prices.push_back(price);
        int n = prices.size();
        int count = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            if (prices[i] <= price) count++;
            else return count;
        }
        return count;
    }
};

class StockSpannerOptimal
{
    stack<pair<int, int>> st;
    int index;

public:
    StockSpannerOptimal()
    {
        index = -1;
        while (!st.empty())
        {
            st.pop();
        }
    }

    int next(int price)
    {
        index++;
        while (!st.empty() && st.top().first <= price)
        {
            st.pop();
        }

        int ans = index - (st.empty() ? -1 : st.top().second);

        st.push({price, index});

        return ans;
    }
};
int main()
{
    // Your StockSpanner object will be instantiated and called as such:
    StockSpannerOptimal *obj = new StockSpannerOptimal();

    cout << "Online Stack Span : " << endl;

    cout << obj->next(7) << endl;
    cout << obj->next(2) << endl;
    cout << obj->next(1) << endl;
    cout << obj->next(3) << endl;
    cout << obj->next(3) << endl;
    cout << obj->next(1) << endl;
    cout << obj->next(8) << endl;
    return 0;
}