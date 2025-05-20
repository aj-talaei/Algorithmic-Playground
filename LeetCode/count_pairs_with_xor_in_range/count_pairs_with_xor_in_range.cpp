// Source: https://leetcode.com/problems/count-pairs-with-xor-in-a-range/
// Description:
//   Given an array of non-negative integers `nums` and two integers `low` and `high`,
//   return the number of pairs `(i, j)` with `0 <= i < j < nums.size()` such that
//   `low <= (nums[i] XOR nums[j]) <= high`.
//   We solve this in O(n · log M) time using a binary Trie on the bit‐representations.

#include <vector>
using namespace std;

// Each TrieNode has two children (0 and 1) and a count of how many numbers
// have passed through this node.
struct TrieNode {
    TrieNode* child[2];
    int cnt;
    TrieNode() : cnt(0) {
        child[0] = child[1] = nullptr;
    }
};

class Solution {
    static const int BITS = 15; // Enough for nums[i] ≤ 2·10^4 (<2^15)
    
    // Insert the binary form of x into the Trie.
    void insertTrie(TrieNode* root, int x) {
        for (int b = BITS; b >= 0; --b) {
            int bit = (x >> b) & 1;
            if (!root->child[bit])
                root->child[bit] = new TrieNode();
            root = root->child[bit];
            root->cnt++;
        }
    }
    
    // Count how many numbers currently in the Trie when XORed with x
    // produce a value < limit.
    int countLessThan(TrieNode* root, int x, int limit) {
        int res = 0;
        for (int b = BITS; b >= 0 && root; --b) {
            int xb = (x >> b) & 1;
            int lb = (limit >> b) & 1;
            if (lb == 1) {
                // If we choose the same bit as xb, that prefix stays < limit at this bit
                if (root->child[xb])
                    res += root->child[xb]->cnt;
                // Then follow the opposite branch for further bits
                root = root->child[xb ^ 1];
            } else {
                // Must match xb to stay below limit at this bit
                root = root->child[xb];
            }
        }
        return res;
    }
    
public:
    int countPairs(vector<int>& nums, int low, int high) {
        TrieNode* root = new TrieNode();
        int ans = 0;
        for (int x : nums) {
            // Count pairs with XOR ≤ high, and subtract pairs with XOR < low
            ans += countLessThan(root, x, high + 1)
                 - countLessThan(root, x, low);
            insertTrie(root, x);
        }
        return ans;
    }
};
