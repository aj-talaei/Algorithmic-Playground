// Source: https://leetcode.com/problems/fraction-to-recurring-decimal/
// Description: Given a numerator and denominator, return their fraction as a string.
//              If the fractional part repeats, enclose the repeating portion in parentheses.

#include <string>
#include <unordered_map>
#include <cstdlib>
#include <climits>

using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (denominator == 0) return "";              // undefined
        if (numerator == 0)   return "0";
        
        // Determine sign
        bool negative = ( (long long)numerator * denominator ) < 0;
        
        // Convert to positive long long to avoid overflow
        long long n = llabs((long long)numerator);
        long long d = llabs((long long)denominator);
        
        // Integer part
        long long integerPart = n / d;
        long long rem = n % d;
        string result = negative ? "-" + to_string(integerPart)
                                  : to_string(integerPart);
        
        if (rem == 0) {
            return result;  // no fractional part
        }
        
        // Fractional part
        result.push_back('.');
        // Map remainder -> position in result string
        unordered_map<long long, int> seen;
        while (rem != 0) {
            if (seen.count(rem)) {
                // Insert '(' at the position where this remainder first appeared
                result.insert(seen[rem], 1, '(');
                result.push_back(')');
                break;
            }
            seen[rem] = result.size();
            rem *= 10;
            int digit = rem / d;
            result.push_back('0' + digit);
            rem %= d;
        }
        
        return result;
    }
};

