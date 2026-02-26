#include <iostream>
using namespace std;

class Bank
{
private:
    vector<long long> balance;
    int n;

    bool isValid(int account)
    {
        return account >= 1 && account <= n;
    }

public:
    Bank(vector<long long> &balance)
    {
        this->balance = balance;
        n = balance.size();
    }

    bool transfer(int account1, int account2, long long money)
    {
        if (!isValid(account1) || !isValid(account2) || balance[account1 - 1] < money)
            return false;

        balance[account1 - 1] -= money;
        balance[account2 - 1] += money;
        return true;
    }

    bool deposit(int account, long long money)
    {
        if (!isValid(account))
            return false;

        balance[account - 1] += money;
        return true;
    }

    bool withdraw(int account, long long money)
    {
        if (!isValid(account) || balance[account - 1] < money)
            return false;

        balance[account - 1] -= money;
        return true;
    }
};
/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */

int main()
{
    vector<long long> balances = {10, 100, 20, 50, 30};

    Bank bank(balances);
    cout << "Simple Bank System : " << endl;
    cout << bank.withdraw(3, 10) << endl;    // true
    cout << bank.transfer(5, 1, 20) << endl; // true
    cout << bank.deposit(5, 20) << endl;     // true
    cout << bank.transfer(3, 4, 15) << endl; // false
    cout << bank.withdraw(10, 50) << endl;   // false

    return 0;
}