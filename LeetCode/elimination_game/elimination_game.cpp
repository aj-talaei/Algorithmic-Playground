// Source: https://leetcode.com/problems/elimination-game
// Description: Given a list of integers from 1 to n, repeatedly eliminate every other number
// from left to right, then right to left, until one number remains. Return that number.

class Solution {
public:
    int lastRemaining(int n) {
        bool left = true;
        int remaining = n;
        int step = 1;
        int head = 1;
        
        while (remaining > 1) {
            // If we're moving left-to-right, or there are an odd number of elements
            // (so the last element in a right-to-left pass gets removed),
            // the head advances by 'step'.
            if (left || (remaining & 1)) {
                head += step;
            }
            // Half the elements survive each round
            remaining >>= 1;
            // Distance between consecutive survivors doubles
            step <<= 1;
            // Alternate direction
            left = !left;
        }
        
        return head;
    }
};
