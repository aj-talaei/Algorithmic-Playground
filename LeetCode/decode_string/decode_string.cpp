// Source: https://leetcode.com/problems/decode-string/
// Description: Decode strings encoded with the rule k[encoded_string], where the contents 
// inside the brackets are repeated exactly k times. Nested encodings are supported.

#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    string decodeString(const string& s) {
        stack<int> counts;
        stack<string> results;
        string current;
        int num = 0;
        
        for (char c : s) {
            if (isdigit(c)) {
                // build the repeat count
                num = num * 10 + (c - '0');
            }
            else if (c == '[') {
                // push the count and the current built string
                counts.push(num);
                results.push(current);
                num = 0;
                current.clear();
            }
            else if (c == ']') {
                // pop and build the repeated substring
                int repeat = counts.top(); counts.pop();
                string temp = results.top(); results.pop();
                while (repeat-- > 0) {
                    temp += current;
                }
                current = move(temp);
            }
            else {
                // accumulate letters
                current.push_back(c);
            }
        }
        
        return current;
    }
};
