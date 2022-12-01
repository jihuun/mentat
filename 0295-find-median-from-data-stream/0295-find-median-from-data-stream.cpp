class MedianFinder {
    //      max   min
    //  1 2 (3)   (4) 5 6
    priority_queue<int, vector<int>, greater<int>> minh;
    priority_queue<int, vector<int>, less<int>> maxh;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        // 1. insert
        if (maxh.empty() || num > maxh.top()) {
            minh.push(num);
        } else {
            maxh.push(num);
        }
        // 2. re-balancing
        if (maxh.size() > minh.size() + 1) {
            minh.push(maxh.top());
            maxh.pop();
        } else if (maxh.size() + 1 < minh.size()) {
            maxh.push(minh.top());
            minh.pop();
        }
    }
    
    double findMedian() {
        if (maxh.size() > minh.size())    
            return (double)maxh.top();
        else if (maxh.size() < minh.size())    
            return (double)minh.top();
        else
            return (double)((maxh.top() + minh.top()) * 0.5);
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */