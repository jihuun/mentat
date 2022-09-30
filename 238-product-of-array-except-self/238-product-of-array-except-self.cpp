/*

ret[]   [1]*[2]*[3]   [0]*[2]*[3]   [0]*[1]*[3]   [0]*[1]*[2]
l->r:   1             1*[0]         1*[0]*[1]     1*[0]*[1]*[2]
l<-r:   *[3]*[2]*[1]  *[3]*[2]      *[3]          1

*/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prod(nums.size(), 0);
        int temp = 1;
        for (int i = 0; i < nums.size(); i++) {
            prod[i] = temp;
            temp *= nums[i];
        }
        // after that prod[last idx] got a answer
        temp = 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            prod[i] *= temp;
            temp *= nums[i];
        }
        // after that prod[0] ~ prod[last idx -1] got a answer
        return prod;
    }
};