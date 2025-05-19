// Problem: Count and Say
// The count-and-say sequence is the sequence of strings beginning as follows:
//   1, 11, 21, 1211, 111221, ...
// 1 is read off as "one 1" → 11.
// 11 is read off as "two 1s" → 21.
// 21 is read off as "one 2, then one 1" → 1211.
// Given an integer n, return the nth term of this sequence.

class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        for (int i = 1; i < n; i++) {
            string t;
            int j = 0, m = s.size();
            while (j < m) {
                int k = j + 1;
                while (k < m && s[k] == s[j]) k++;
                t.push_back(char('0' + (k - j)));
                t.push_back(s[j]);
                j = k;
            }
            s.swap(t);
        }
        return s;
    }
};
