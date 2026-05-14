#include <vector>
#include <string>
#include <sstream>

using namespace std;

// A struct to hold our parsed data cleanly
struct Transaction {
    string name;
    int time;
    int amount;
    string city;
    string raw;      // Keep the original string to return later
    bool invalid;    // Flag to mark if it breaks any rules
};

class Solution {
public:
    vector<string> invalidTransactions(vector<string>& transactions) {
        vector<Transaction> parsedData;
        
        // 1. Parse all the strings into our struct
        for (const string& t : transactions) {
            stringstream ss(t);
            string name, timeStr, amountStr, city;
            
            getline(ss, name, ',');
            getline(ss, timeStr, ',');
            getline(ss, amountStr, ',');
            getline(ss, city, ',');
            
            parsedData.push_back({
                name, 
                stoi(timeStr), 
                stoi(amountStr), 
                city, 
                t, 
                false
            });
        }
        
        // 2. Evaluate all rules
        for (int i = 0; i < parsedData.size(); i++) {
            // Rule 1: Amount exceeds 1000
            if (parsedData[i].amount > 1000) {
                parsedData[i].invalid = true;
            }
            
            // Rule 2: Same name, different city, within 60 minutes
            for (int j = i + 1; j < parsedData.size(); j++) {
                if (parsedData[i].name == parsedData[j].name && 
                    parsedData[i].city != parsedData[j].city && 
                    abs(parsedData[i].time - parsedData[j].time) <= 60) {
                    
                    // Both transactions are considered invalid
                    parsedData[i].invalid = true;
                    parsedData[j].invalid = true;
                }
            }
        }
        
        // 3. Collect the invalid transactions
        vector<string> sol;
        for (const auto& t : parsedData) {
            if (t.invalid) {
                sol.push_back(t.raw);
            }
        }
        
        return sol;
    }
};

