class Solution {
    /*
     1 2 3 4 
     2 3 4 5
     
         1 
      2      5
        3  4  
    
    */
public:
    int act(vector<int>& vis, vector<int>& nums, int h) {
        if (h < 0)
            return 0;
        if (vis[h] != -1)
            return vis[h];
        vis[h] = max(act(vis, nums, h - 1), act(vis, nums, h - 2) + nums[h]);
        return vis[h];
    }
    int rob(vector<int>& nums) {
        vector<int> n1, n2;
        vector<int> vis1(101, -1), vis2(101, -1);
        
        for (int i = 0; i < nums.size(); i++) {
            if (i == 0) {
                n2.push_back(nums[i]);
            } else if (i == nums.size() - 1) {
                n1.push_back(nums[i]);
            } else {
                n1.push_back(nums[i]);
                n2.push_back(nums[i]);
            }
        }
        return max(act(vis1, n1, n1.size() - 1), act(vis2, n2, n2.size() - 1)); 
    }
};