#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <cctype> // For isalnum

using namespace std;

class Solution {
public:
    // Helper function to validate the Code format
    bool isValidCodeFormat(const string& s) {
        if (s.empty()) return false;
        for (char c : s) {
            // Check if char is NOT alphanumeric AND NOT an underscore
            if (!isalnum(c) && c != '_') {
                return false;
            }
        }
        return true;
    }

    // Helper function to validate the Business Line
    bool isValidBusinessLine(const string& s) {
        // Using a static set for fast lookup
        static const unordered_set<string> validLines = {
            "electronics", "grocery", "pharmacy", "restaurant"
        };
        return validLines.count(s);
    }

    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        int n = code.size();
        
        // Store valid coupons as {businessLine, code} to enable easy sorting
        vector<pair<string, string>> validCoupons;
        
        for (int i = 0; i < n; i++) {
            // Check all 3 conditions:
            bool activeCondition = isActive[i];
            bool businessCondition = isValidBusinessLine(businessLine[i]);
            bool codeCondition = isValidCodeFormat(code[i]);
            
            if (activeCondition && businessCondition && codeCondition) {
                validCoupons.push_back({businessLine[i], code[i]});
            }
        }
        
        // Sort primarily by Business Line, secondarily by Code (alphabetical)
        sort(validCoupons.begin(), validCoupons.end());
        
        // Extract just the codes for the result
        vector<string> result;
        for (const auto& p : validCoupons) {
            result.push_back(p.second);
        }
        
        return result;
    }
};
