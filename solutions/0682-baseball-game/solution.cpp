class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> a;

        for (int i = 0; i < operations.size(); i++) {
            if (operations[i] == "+") {
                int n = a.size();
                a.push_back(a[n - 1] + a[n - 2]);
            }
            else if (operations[i] == "D") {
                a.push_back(2 * a.back());
            }
            else if (operations[i] == "C") {
                a.pop_back();
            }
            else {
                a.push_back(stoi(operations[i]));
            }
        }

        int sum = 0;
        for (int x : a) {
            sum += x;
        }
        return sum;
    }
};

