class Solution {
public:
    static bool custom_cmp(int a, int b) {
        string sa = std::to_string(a);
        string sb = std::to_string(b);
        if (sa + sb > sb + sa)
            return true; // 순서 a b 유지
        else
            return false;
    }
    string largestNumber(vector<int>& nums) {
        std::string ret;
        std::sort(nums.begin(), nums.end(), custom_cmp);
        for (auto it: nums)
            ret = ret + std::to_string(it);
        if (ret[0] == '0')
            return "0";
        return ret;
    }
};