class Solution {
    bool condition(vector<int> piles, int speed, int limit_h) {
        // check the speed is enough to finish all of banana piles
        int tot_time = 0;
        for (int i = 0; i < piles.size(); i++)
            tot_time += (piles[i] / speed) + (piles[i] % speed != 0);
        if (tot_time <= limit_h)
            return true;
        return false;
        
        
        /*
        int idx = 0;
        
        while (idx < piles.size()) {
            if (speed >= piles[idx]) {
                piles[idx] = 0;
                idx++;
            } else {
                piles[idx] = piles[idx] - speed;
            }
            hour--;
            if (hour < 0)
                break;
        }
        if (hour >= 0)
            return true;
        return false;
        */
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *std::max_element(piles.begin(), piles.end());
        int mid = 0;
        
        while (left < right) {
            mid = left + (right - left) / 2;
            if (condition(piles, mid, h))   // enough speed. much less speed could be enough as well.
                right = mid;
            else                            // too slow                           
                left = mid + 1;
        }
        return left;
    }
};