// Source : https://leetcode.com/problems/peeking-iterator/

class PeekingIterator : public Iterator {
private:
    int nextVal;
    bool hasNextVal;

    void advance() {
        hasNextVal = Iterator::hasNext();
        if (hasNextVal) {
            nextVal = Iterator::next();
        }
    }

public:
    PeekingIterator(const vector<int>& nums) : Iterator(nums) {
        advance(); // Preload the first value
    }

    // Returns the next element in the iteration without advancing the iterator.
    int peek() {
        return nextVal;
    }

    int next() {
        int current = nextVal;
        advance(); // Preload the next value
        return current;
    }

    bool hasNext() const {
        return hasNextVal;
    }
};
