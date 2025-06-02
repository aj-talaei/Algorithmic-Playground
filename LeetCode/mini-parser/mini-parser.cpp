// Source: https://leetcode.com/problems/mini-parser/

class Solution {
public:
    NestedInteger deserialize(string s) {
        int pos = 0;
        if (s[pos] != '[') {
            return parseNumber(s, pos);
        }
        pos++; // skip the initial '['
        return parseList(s, pos);
    }

private:
    NestedInteger parseList(const string& s, int& pos) {
        NestedInteger ni;
        while (pos < s.size() && s[pos] != ']') {
            if (s[pos] == ',') {
                pos++;
            } else if (s[pos] == '[') {
                pos++; // skip '['
                ni.add(parseList(s, pos));
            } else {
                ni.add(parseNumber(s, pos));
            }
        }
        pos++; // skip ']'
        return ni;
    }

    NestedInteger parseNumber(const string& s, int& pos) {
        int sign = 1;
        if (s[pos] == '-') {
            sign = -1;
            pos++;
        }
        int num = 0;
        while (pos < s.size() && isdigit(s[pos])) {
            num = num * 10 + (s[pos] - '0');
            pos++;
        }
        return NestedInteger(sign * num);
    }
};
