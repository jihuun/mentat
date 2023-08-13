class NumArray {
public:
    unordered_map<int, int> table;
    NumArray(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            table[i] = sum;
        }
    }
    // 0 1 2 3 4
    //   ^^^^^
    
    int sumRange(int left, int right) {
        if (left - 1 < 0)
            return table[right];
        return table[right] - table[left - 1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */