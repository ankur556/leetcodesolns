class Solution {
public:
    int minLights(vector<int>& lights) {
        int n = lights.size();
        vector<bool> lit(n, false);
        vector<int> diff(n + 1, 0);
        for(int i = 0; i < n; i++) {
            if(lights[i] > 0) {
                int left = max(0, i - lights[i]);
                int right = min(n - 1, i + lights[i]);
                diff[left]++;
                diff[right + 1]--;
            }
        }
        int currentCoverage = 0;
        for(int i = 0; i < n; i++) {
            currentCoverage += diff[i];
            if(currentCoverage > 0) {
                lit[i] = true;
            }
        }
        int additionalBulbs = 0;
        for(int i = 0; i < n; i++) {
            if(!lit[i]) {
                additionalBulbs++;
                i += 2; 
            }
        }
        
        return additionalBulbs;
    }
};
