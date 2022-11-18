class Solution {
    bool is_not_common(vector<string> strs, int idx) {
        string cmps = strs[0].substr(0, idx + 1);
        for (int i = 0; i < strs.size(); i++) {
            if (strs[i].substr(0, idx + 1) != cmps)
                return true;
        }
        return false;
    }
public:
    string longestCommonPrefix(vector<string>& strs) {
        int left = 0;
        int right = strs[0].length();
        for (int i = 1; i < strs.size(); i++) {
            right = std::min(right, (int)strs[i].length());
        }
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (is_not_common(strs, mid))
                right = mid;
            else
                left = mid + 1;
        }
        return strs[0].substr(0, left);
    }
};