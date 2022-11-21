class SparseVector {
public:
    vector<pair<int, int>> v;
    SparseVector(vector<int> &nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                v.push_back(make_pair(i, nums[i]));    
            }
        }
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int dp = 0;
        int p = 0, q = 0;
        while (p < v.size() && q < vec.v.size()) {
            if (v[p].first == vec.v[q].first) {
                dp += v[p].second * vec.v[q].second;
                p++;
                q++;
            } else if (v[p].first > vec.v[q].first) {
                q++;
            } else {
                p++;
            }
        }
        return dp;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);