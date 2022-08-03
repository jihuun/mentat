class MyCalendar {
    map<int, int> cal;
public:
    MyCalendar() {
        cal.clear();
    }
    
    bool book(int start, int end) {
        /*
        upper_bound(n): n보다 큰 값중에 첫번째 iter
        lower_bound(n): n보다 큰거나 같은 값중에 첫번째 iter
        */
        auto it = cal.upper_bound(start);
        if (it == cal.end() || end <= it->second)
            cal[end] = start;
        else
            return false;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */