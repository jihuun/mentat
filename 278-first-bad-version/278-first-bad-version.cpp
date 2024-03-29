// The API isBadVersion is defined for you.
// bool isBadVersion(int version);
// 1 1 1 1 0 0 

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1, right = n, mid = 0;
        while (left < right) {
            mid = left + (right - left) / 2;
            if (isBadVersion(mid) == true)
                right = mid;
            else 
                left = mid + 1;
        }
        return left;
    }
};