// Problem: https://leetcode.com/problems/implement-trie-prefix-tree/
// Implement a Trie (Prefix Tree) with insert, search, and startsWith methods.
// All inputs are lowercase English letters (a-z). The Trie supports storing and 
// querying whether a word exists or if any word starts with a given prefix.

#include <string>
#include <unordered_map>
using namespace std;

class TrieNode {
public:
    bool isWord = false;
    unordered_map<char, TrieNode*> children;
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    ~Trie() {
        clear(root);
    }

    void insert(const string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            if (!node->children.count(ch)) {
                node->children[ch] = new TrieNode();
            }
            node = node->children[ch];
        }
        node->isWord = true;
    }

    bool search(const string& word) const {
        TrieNode* node = find(word);
        return node && node->isWord;
    }

    bool startsWith(const string& prefix) const {
        return find(prefix) != nullptr;
    }

private:
    TrieNode* root;

    TrieNode* find(const string& key) const {
        TrieNode* node = root;
        for (char ch : key) {
            if (!node->children.count(ch)) return nullptr;
            node = node->children[ch];
        }
        return node;
    }

    void clear(TrieNode* node) {
        for (auto& [_, child] : node->children) {
            clear(child);
            delete child;
        }
    }
};
