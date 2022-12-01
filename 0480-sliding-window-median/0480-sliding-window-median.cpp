class Solution {
    //  maxh     minh
    // 1 2 (3)   (4) 5 6
    // |    |
    // |    maxh.rbegin() or --maxh.end()
    // maxh.begin()
    multiset<int, less<int>> maxh; // inc order
    multiset<int, less<int>> minh;
public:
    void add_num(int val) {
        // 1. insert
        if (maxh.empty() || val > *maxh.rbegin())   
            minh.insert(val);
        else
            maxh.insert(val);
        
        // 2. re-balance
        if (maxh.size() > minh.size() + 1) {
            minh.insert(*(--maxh.end()));
            maxh.erase(--maxh.end()); // ~~FIXME: modify to O(1)~~
        } else if (maxh.size() + 1 < minh.size()) {
            maxh.insert(*minh.begin());
            minh.erase(minh.begin());
        }
    }
    void del_num(int val) {
        auto max_it = maxh.find(val);
        auto min_it = minh.find(val);
        // 1. delete
        if (max_it != maxh.end()) {
            maxh.erase(max_it);
        } else if (min_it != minh.end()) {
            minh.erase(min_it);
        }
        // 2. re-balance
        if (maxh.size() > minh.size() + 1) {
            minh.insert(*(--maxh.end()));
            maxh.erase(--maxh.end()); // ~~FIXME: modify to O(1)~~
        } else if (maxh.size() + 1 < minh.size()) {
            maxh.insert(*minh.begin());
            minh.erase(minh.begin());
        }
    }
    
    double get_median(void) {
        if (maxh.size() > minh.size())
            return (double)*maxh.rbegin();
        else if (maxh.size() < minh.size())
            return (double)*minh.begin();
        else
            return ((double)*maxh.rbegin() + (double)*minh.begin()) * 0.5;
    }
    
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> ret;
        int nsize = nums.size();
        
        for (int i = 0; i < k; i++)
            add_num(nums[i]);
        ret.push_back(get_median());
        
        for (int i = 1; i < nsize - k + 1; i++) {
            del_num(nums[i - 1]);
            add_num(nums[i + k - 1]);
            ret.push_back(get_median());
        }
        return ret;
    }
};