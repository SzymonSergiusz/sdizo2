#include <queue>
using namespace std;

class PriorityQueue {
private:
    priority_queue<int> pq;

public:
    void push(int x) {
        pq.push(x);
    }

    void pop() {
        pq.pop();
    }

    int top() {
        return pq.top();
    }

    bool empty() {
        return pq.empty();
    }
};
