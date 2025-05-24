// Source: https://leetcode.com/problems/finding-mk-average/
// Description: Implement MKAverage for a stream: keep the last m elements, drop the k smallest
//              and k largest, and return the average (floored) of the remaining m−2k elements.
//              If fewer than m elements have been seen, return -1.
//              Uses Fenwick trees to maintain counts and prefix sums over the value range [1..100000].

#include <vector>
#include <queue>
using namespace std;

class Fenwick {
    int n;
    vector<long long> f;
public:
    Fenwick(int _n): n(_n), f(n+1, 0) {}
    // add v at index i
    void update(int i, long long v) {
        for (; i <= n; i += i & -i) f[i] += v;
    }
    // sum of [1..i]
    long long query(int i) const {
        long long s = 0;
        for (; i > 0; i -= i & -i) s += f[i];
        return s;
    }
    // find smallest idx such that query(idx) >= k (1-based)
    int findByOrder(long long k) const {
        int idx = 0;
        int bitMask = 1 << 17;  // >= 100000 (2^17 = 131072)
        for (; bitMask; bitMask >>= 1) {
            int t = idx + bitMask;
            if (t <= n && f[t] < k) {
                idx = t;
                k -= f[t];
            }
        }
        return idx + 1;
    }
};

class MKAverage {
    int m, k;
    queue<int> q;
    Fenwick bitCount, bitSum;
    long long totalSum = 0;

    // sum of the smallest x elements in current window
    long long sumFirst(int x) const {
        if (x <= 0) return 0;
        int val = bitCount.findByOrder(x);
        long long cntBefore = bitCount.query(val - 1);
        long long sumBefore = bitSum.query(val - 1);
        long long rem = x - cntBefore;
        return sumBefore + rem * val;
    }

public:
    MKAverage(int m_, int k_)
        : m(m_), k(k_), bitCount(100000), bitSum(100000) {}

    void addElement(int num) {
        // enqueue new
        q.push(num);
        bitCount.update(num, 1);
        bitSum.update(num, num);
        totalSum += num;

        // evict old if needed
        if ((int)q.size() > m) {
            int old = q.front(); q.pop();
            bitCount.update(old, -1);
            bitSum.update(old, -old);
            totalSum -= old;
        }
    }

    int calculateMKAverage() {
        if ((int)q.size() < m) return -1;
        // sum of k smallest:
        long long sumSmall = sumFirst(k);
        // sum of k largest = totalSum - sum of first (m-k)
        long long sumUptoMk = sumFirst(m - k);
        long long sumLarge = totalSum - sumUptoMk;
        long long midSum = totalSum - sumSmall - sumLarge;
        return int(midSum / (m - 2 * k));
    }
};

