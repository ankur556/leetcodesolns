class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& s) {
        // 1. Count Students
        int noofones = 0;
        int noofzeros = 0;
        for (int i = 0; i < students.size(); i++) {
            if (students[i] == 1) { noofones++; } 
            else { noofzeros++; }
        }

        // 2. Count Sandwiches
        int noofoness = 0;
        int noofzeross = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 1) { noofoness++; } 
            else { noofzeross++; }
        }

        // Case A: Perfect match (Or we have surplus of both, which is mathematically impossible if sizes are equal)
        // If the number of 1s and 0s matches exactly between students and sandwiches, everyone eats.
        if (noofones == noofoness) {
            return 0;
        }

        // Case B: We are deficient in students who want 1s (Square)
        // Meaning: We have too many '1' sandwiches and not enough '1' students.
        else if (noofones < noofoness) {
            for (int i = 0; i < s.size(); i++) {
                if (s[i] == 1) {
                    if (noofones > 0) {
                        noofones--; // Student eats
                    } else {
                        // A '1' sandwich is on top, but we ran out of '1' students.
                        // The line jams here. Return remaining sandwiches.
                        return s.size() - i;
                    }
                } 
                // We don't worry about s[i] == 0 here because we know we have EXTRA 0 students
                // in this branch. They will definitely eat.
            }
        }
        
        // Case C: We are deficient in students who want 0s (Circular)
        // Meaning: We have too many '0' sandwiches and not enough '0' students.
        else { 
            for (int i = 0; i < s.size(); i++) {
                if (s[i] == 0) {
                    if (noofzeros > 0) {
                        noofzeros--; // Student eats
                    } else {
                        // A '0' sandwich is on top, but we ran out of '0' students.
                        // The line jams here.
                        return s.size() - i;
                    }
                }
                // We don't worry about s[i] == 1 here because we know we have EXTRA 1 students.
            }
        }
        
        return 0;
    }
};
