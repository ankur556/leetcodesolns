class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int low=0;
        int high=numbers.size()-1;
        while(high>low){
            if(numbers[high]+numbers[low]>target){
                high--;
            }
            else if(numbers[high]+numbers[low]<target){low++;}
            else if(numbers[high]+numbers[low]==target){vector<int> a;a.push_back(low+1);a.push_back(high+1);return a;}
        }
        vector<int> t;
        t.push_back(1);
        t.push_back(2);
        return t;
        
    }
};
