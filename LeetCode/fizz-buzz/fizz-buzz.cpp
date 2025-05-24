// Source: https://leetcode.com/problems/fizz-buzz/
// Description: Return a list of strings for numbers from 1 to n, but for multiples of 3 use "Fizz",
//              for multiples of 5 use "Buzz", and for multiples of both 3 and 5 use "FizzBuzz".

#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> result;
        result.reserve(n);
        for (int i = 1; i <= n; ++i) {
            string s;
            if (i % 3 == 0) s += "Fizz";
            if (i % 5 == 0) s += "Buzz";
            if (s.empty()) s = to_string(i);
            result.push_back(move(s));
        }
        return result;
    }
};

