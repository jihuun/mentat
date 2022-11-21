class SparseVector {
public:
    //vector<int> v;
    unordered_map<int, int> v;
    SparseVector(vector<int> &nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                v[i] = nums[i];    
            }
        }
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int dp = 0;
        for (auto it: vec.v) {
            if (it.second != 0 && v[it.first] != 0) {
                dp += it.second * v[it.first];
            }
        }
        return dp;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);