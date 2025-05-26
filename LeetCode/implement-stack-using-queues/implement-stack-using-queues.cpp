// Problem: https://leetcode.com/problems/implement-stack-using-queues/
// Implement a stack using one or two queues. Support push, pop, top, and empty operations.
// Only standard queue operations are allowed: push to back, pop/peek from front, size, and isEmpty.

#include <queue>
using namespace std;

class MyStack {
private:
    queue<int> q;

public:
    void push(int x) {
        q.push(x);
        int size = q.size();
        // Rotate all elements except the last pushed to simulate stack behavior
        while (--size) {
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        int top = q.front();
        q.pop();
        return top;
    }

    int top() {
        return q.front();
    }

    bool empty() {
        return q.empty();
    }
};
