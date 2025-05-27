// Problem: Integer to English Words
// URL: https://leetcode.com/problems/integer-to-english-words/
// Convert a non-negative integer to its English words representation.

#include <string>
#include <vector>
using namespace std;

class Solution {
private:
    vector<string> below20{
        "Zero","One","Two","Three","Four","Five","Six","Seven","Eight","Nine",
        "Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen",
        "Seventeen","Eighteen","Nineteen"
    };
    vector<string> tens{
        "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"
    };
    vector<string> thousands{
        "","Thousand","Million","Billion"
    };
    
    // Convert a number < 1000 into words (with a trailing space if non-empty)
    string helper(int num) {
        if (num == 0) 
            return "";
        else if (num < 20) 
            return below20[num] + " ";
        else if (num < 100) 
            return tens[num/10] + " " + helper(num % 10);
        else 
            return below20[num/100] + " Hundred " + helper(num % 100);
    }

public:
    string numberToWords(int num) {
        if (num == 0) 
            return "Zero";
        
        string result;
        int group = 0;
        
        while (num > 0) {
            int chunk = num % 1000;
            if (chunk != 0) {
                string part = helper(chunk) + thousands[group];
                if (!result.empty()) 
                    part += " ";
                result = part + result;
            }
            num /= 1000;
            ++group;
        }
        
        // Remove any trailing space
        if (!result.empty() && result.back() == ' ')
            result.pop_back();
        
        return result;
    }
};
