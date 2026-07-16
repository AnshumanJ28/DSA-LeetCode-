/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *		struct Data;
 * 		Data* data;
 *  public:
 *		Iterator(const vector<int>& nums);
 * 		Iterator(const Iterator& iter);
 *
 * 		// Returns the next element in the iteration.
 *		int next();
 *
 *		// Returns true if the iteration has more elements.
 *		bool hasNext() const;
 *	};
 */

class PeekingIterator : public Iterator {
public:
    int nextElement;
    bool hasNextElement;

    PeekingIterator(const vector<int>& nums) : Iterator(nums) {
        hasNextElement = Iterator::hasNext();

        if (hasNextElement) {
            nextElement = Iterator::next();
        }
    }

    int peek() {
        return nextElement;
    }

    int next() {
        int ans = nextElement;

        hasNextElement = Iterator::hasNext();

        if (hasNextElement) {
            nextElement = Iterator::next();
        }

        return ans;
    }

    bool hasNext() const {
        return hasNextElement;
    }
};