#include <vector>
#include <string>
#include <stack>
#include <sstream>

using namespace std;

class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> result(n, 0);
        stack<int> st;
        int prev_time = 0;

        for (const string& log : logs) {
            // 1. Parse the log string "id:type:timestamp"
            int first_colon = log.find(':');
            int second_colon = log.find(':', first_colon + 1);
            
            int id = stoi(log.substr(0, first_colon));
            string type = log.substr(first_colon + 1, second_colon - first_colon - 1);
            int time = stoi(log.substr(second_colon + 1));

            // 2. Handle "start"
            if (type == "start") {
                // If there's a function already running, add the time it ran 
                // BEFORE this new function interrupted it.
                if (!st.empty()) {
                    result[st.top()] += time - prev_time;
                }
                
                st.push(id);
                prev_time = time; // Update pointer to current start
            }
            // 3. Handle "end"
            else {
                // The function at the top is finishing.
                // Duration is inclusive: time - prev_time + 1
                result[st.top()] += time - prev_time + 1;
                st.pop();
                
                // Since "end" consumes the whole time unit, the next available
                // time unit is time + 1
                prev_time = time + 1;
            }
        }

        return result;
    }
};
