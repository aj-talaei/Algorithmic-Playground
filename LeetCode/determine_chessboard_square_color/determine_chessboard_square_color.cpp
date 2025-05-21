// Source: https://leetcode.com/problems/determine-color-of-a-chessboard-square/
// Description: Given a chessboard coordinate (e.g., "a1"), return true if the square is white, false if black.

#include <string>
using namespace std;

class Solution {
public:
    bool squareIsWhite(const string& coordinates) {
        // Columns 'a'..'h' map to 1..8; rows '1'..'8' map to 1..8.
        // A square is white iff its column and row have opposite parity.
        int col = coordinates[0] - 'a' + 1;
        int row = coordinates[1] - '0';
        return (col % 2) != (row % 2);
    }
};
