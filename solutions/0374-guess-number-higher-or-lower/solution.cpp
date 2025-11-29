/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int l = 1;
        int h = n;
        // int c;
        while (l <= h) {
            int mid = l+(h - l) / 2;
            int k = guess(mid);
            if (k == 0) {
                return  mid;
            } else if (k == -1) {
                h = mid - 1;
            } else if (k == 1) {
                l = mid + 1;
            }
        }
        return -1;
    }

};
