#include <vector>
#include <algorithm>

class Solution {
public:
    bool isturn(int turn, int p1sum, int p2sum, int lptr, int rptr, const std::vector<int>& nums) {
        // Base case: only one element left
        if (lptr == rptr) {
            if (turn % 2 != 0) { // Player 1's turn
                p1sum += nums[lptr];
            } else {             // Player 2's turn
                p2sum += nums[lptr];
            }
            return p1sum >= p2sum; // Player 1 wins ties
        }

        if (turn % 2 != 0) {
            // Player 1's turn: Player 1 wins if either choice leads to a win
            bool pickLeft  = isturn(turn + 1, p1sum + nums[lptr], p2sum, lptr + 1, rptr, nums);
            bool pickRight = isturn(turn + 1, p1sum + nums[rptr], p2sum, lptr, rptr - 1, nums);
            return pickLeft || pickRight;
        } else {
            // Player 2's turn: Player 2 plays optimally to stop Player 1,
            // so Player 1 wins only if BOTH choices still result in a win for Player 1
            bool pickLeft  = isturn(turn + 1, p1sum, p2sum + nums[lptr], lptr + 1, rptr, nums);
            bool pickRight = isturn(turn + 1, p1sum, p2sum + nums[rptr], lptr, rptr - 1, nums);
            return pickLeft && pickRight;
        }
    }

    bool predictTheWinner(std::vector<int>& nums) {
        return isturn(1, 0, 0, 0, nums.size() - 1, nums);
    }
};