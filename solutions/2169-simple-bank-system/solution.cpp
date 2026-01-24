#include <vector>

using namespace std;

class Bank {
private:
    vector<long long> accounts;
    int n;

    // Helper to check if account exists (1-based index)
    bool isValid(int account) {
        return account >= 1 && account <= n;
    }

public:
    Bank(vector<long long>& balance) {
        accounts = balance; // This makes a copy of the balance vector
        n = balance.size();
    }
    
    bool transfer(int account1, int account2, long long money) {
        // Validate both accounts and check if account1 has enough funds
        if (isValid(account1) && isValid(account2) && accounts[account1 - 1] >= money) {
            accounts[account1 - 1] -= money;
            accounts[account2 - 1] += money;
            return true;
        }
        return false;
    }
    
    bool deposit(int account, long long money) {
        if (isValid(account)) {
            accounts[account - 1] += money;
            return true;
        }
        return false;
    }
    
    bool withdraw(int account, long long money) {
        if (isValid(account) && accounts[account - 1] >= money) {
            accounts[account - 1] -= money;
            return true;
        }
        return false;
    }
};
