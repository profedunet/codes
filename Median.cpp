#include <iostream>
#include<queue>
using namespace std;

class MedianFinder {
	priority_queue<int> maxHeap;
	priority_queue<int, vector<int>, std::greater<int> > minHeap;
public:

	// Adds a number into the data structure.
	void addNum(int num) {
		int val;
		if (maxHeap.empty()) {
			maxHeap.push(num);
		}
		else if (minHeap.empty()) {
			if (num < maxHeap.top()) {
				val = maxHeap.top();maxHeap.pop();
				maxHeap.push(num);
				minHeap.push(val);
			}
			else
				minHeap.push(num);
		}
		else {
			if (num < maxHeap.top()) {
				maxHeap.push(num);
			}
			else if (num > minHeap.top()) {
				val = minHeap.top();minHeap.pop();
				minHeap.push(num);
				maxHeap.push(val);
			}
			else
				maxHeap.push(num);
			while (maxHeap.size() > minHeap.size() + 1) {
				val = maxHeap.top();
				maxHeap.pop();
				minHeap.push(val);
			}
		}

	}

	// Returns the median of current data stream
	double findMedian() {
		if (maxHeap.size() == minHeap.size()) {
			return (maxHeap.top() + minHeap.top()) / 2.0;
		}
		else {
			return maxHeap.top();
		}
	}
};

int main() {
	MedianFinder medianFinder;
	medianFinder.addNum(5);
	medianFinder.addNum(14);
	medianFinder.addNum(25);
	cout << medianFinder.findMedian();
}
