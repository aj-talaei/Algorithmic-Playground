// Problem: https://leetcode.com/problems/implement-queue-using-stacks/
// Implement a queue using two stacks. Support push, pop, peek, and empty operations.
// Only standard stack operations are allowed: push, pop, top, size, and isEmpty.

#include <stack>
using namespace std;

class MyQueue {
private:
    stack<int> inStack, outStack;

    // Transfer elements only when needed
    void transferIfNeeded() {
        if (outStack.empty()) {
            while (!inStack.empty()) {
                outStack.push(inStack.top());
                inStack.pop();
            }
        }
    }

public:
    void push(int x) {
        inStack.push(x);
    }

    int pop() {
        transferIfNeeded();
        int val = outStack.top();
        outStack.pop();
        return val;
    }

    int peek() {
        transferIfNeeded();
        return outStack.top();
    }

    bool empty() {
        return inStack.empty() && outStack.empty();
    }
};
