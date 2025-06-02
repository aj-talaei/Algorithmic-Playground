// Source: https://leetcode.com/problems/maximum-value-at-a-given-index-in-a-bounded-array/

class Solution {
public:
    using ll = long long;

    int maxValue(int n, int index, int maxSum) {
        int left = 1, right = maxSum, result = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (isValid(mid, n, index, maxSum)) {
                result = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return result;
    }

private:
    bool isValid(int peak, int n, int index, int maxSum) {
        ll total = peak;
        total += calcSide(index, peak - 1);             // left side
        total += calcSide(n - index - 1, peak - 1);     // right side
        return total <= maxSum;
    }

    ll calcSide(int len, int start) {
        if (start >= len) {
            ll end = start - len + 1;
            return (ll)(start + end) * len / 2;
        } else {
            ll full = (ll)start * (start + 1) / 2;
            return full + (len - start); // remaining ones
        }
    }
};
