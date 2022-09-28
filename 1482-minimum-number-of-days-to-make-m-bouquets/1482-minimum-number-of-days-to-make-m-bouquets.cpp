/*
몇일 뒤에 꽃이 피는지가 적힌 `bloomDay[]` 배열이 주어진다. 꽃이 피면 꽃다발을 만들수 있다. 하나의 꽃다발은 `k`개이어야하고, 반드시 인접한 꽃만 선택할 수 있다. 총 `m`개의 꽃다발을 만든다고 할때, 최소 몇일 뒤에 작업을 완수할수 있는가?
*/
class Solution {
    bool condition(vector<int> bloomDay, int remain_days, int m, int k) {
        // check k's continous subarray are exist m times
        int cont_cnt = 0;
        
        for (int i = 0; i < bloomDay.size(); i++) {
            cont_cnt++;
            if (bloomDay[i] > remain_days) {
                if (cont_cnt-1 >= k)
                    m--;
                cont_cnt = 0;
            } else if (cont_cnt >= k) {
                m--;
                cont_cnt = 0;
            }
            if (m <= 0)
                return true;
        }

        if (cont_cnt >= k)
            m--;
        if (m <= 0)
            return true;
        return false;
        
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if (m * k > bloomDay.size())
            return -1;
        int left = *std::min_element(bloomDay.begin(), bloomDay.end());
        int right = *std::max_element(bloomDay.begin(), bloomDay.end());
        int mid = 0;
        
        while (left < right) {
            mid = left + (right - left) / 2; // the remain days what we have to find
            
            if (condition(bloomDay, mid, m, k)) // check mid days is possible to make bouquet
                right = mid;
            else                                // it's not possible
                left = mid + 1;
        }
        return left;
    }
};