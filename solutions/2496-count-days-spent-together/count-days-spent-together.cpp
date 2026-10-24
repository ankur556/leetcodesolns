class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {

        auto getDayOfYear = [](string date) {
            vector<int> daysInMonths = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
            int month = stoi(date.substr(0, 2));
            int day = stoi(date.substr(3, 2));
            
            int dayOfYear = day;
            for (int i = 0; i < month - 1; ++i) {
                dayOfYear += daysInMonths[i];
            }
            return dayOfYear;
        }; 
        int arriveA = getDayOfYear(arriveAlice);
        int leaveA = getDayOfYear(leaveAlice);
        int arriveB = getDayOfYear(arriveBob);
        int leaveB = getDayOfYear(leaveBob);
        int startOverlap = max(arriveA, arriveB);
        int endOverlap = min(leaveA, leaveB);
        return max(0, endOverlap - startOverlap + 1);
    }
};