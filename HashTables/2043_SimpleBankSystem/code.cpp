#include <iostream>
#include <vector>
using namespace std;

class Bank {
    vector<long long> bal;
    int n;

    bool valid(int acc) {
        return acc >= 1 && acc <= n;
    }

public:
    Bank(vector<long long>& balance) {
        bal = balance;
        n = balance.size();
    }

    bool transfer(int acc1, int acc2, long long money) {
        if (!valid(acc1) || !valid(acc2) || bal[acc1 - 1] < money)
            return false;
        bal[acc1 - 1] -= money;
        bal[acc2 - 1] += money;
        return true;
    }

    bool deposit(int acc, long long money) {
        if (!valid(acc)) return false;
        bal[acc - 1] += money;
        return true;
    }

    bool withdraw(int acc, long long money) {
        if (!valid(acc) || bal[acc - 1] < money) return false;
        bal[acc - 1] -= money;
        return true;
    }
};