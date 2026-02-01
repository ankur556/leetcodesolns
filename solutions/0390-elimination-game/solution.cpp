class Solution {
public:
    int lastRemaining(int n) {
        int head = 1;
        int step = 1;
        int remaining = n;
        bool left = true;

        while (remaining > 1) {
            // The head moves if:
            // 1. We are moving from left to right.
            // 2. We are moving from right to left AND there's an odd number of elements.
            if (left || remaining % 2 == 1) {
                head = head + step;
            }

            // After each round, the distance between numbers doubles
            step *= 2;
            // The count of numbers is halved
            remaining /= 2;
            // Flip the direction
            left = !left;
        }

        return head;
    }
};
