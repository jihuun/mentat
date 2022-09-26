/*

1. linear search
[1,2,3,4, 5,6, 7,8 ,9, 10], days = 5

55 / 5 -> 11

[3,2 ,2,4, 1,4], days = 3

16/3 -> 5.3

[1,2, 3, 1, 1], days = 4

8 / 4 -> 2

2. binary search
[1,2,3,4, 5, 6, 7, 8, 9, 10]   n-time binary search
[1 3 6 10 15 21 28 36 45 55]
            ^
     15         55-15= 30
                30 / 4 -> 7.x
         ^
     10         55-10 = 45
                45 / 4 -> 11.x
                
how to select correct position for each binary search
-> what's the condition for get position by binary search

  - balance by average number

*/

/*
[1,2,3,4, 5, 6, 7, 8, 9, 10]   n-time binary search
[1 3 6 10 15 21 28 36 45 55]
                  ^
*/

class Solution {
    bool condition(vector<int>& weights, int capa, int tgt_days) {
        // check how many days is needed when using capa value for capacity
        // if needed days are less than the target days, it can be a answer
        // else if needed days is larger than tgt_days, it means that, it is too samll to be a capacity
        int days = 1;
        int sum = 0;
        
        for (int i = 0; i < weights.size(); i++) {
            sum += weights[i];
            if (sum > capa) {
                sum = weights[i];
                days++;
            }
        }
        if (days > tgt_days) // if needed days is larger than tgt_days
            return false;
        return true;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        // <up & down game> for matching capacity value. 
        // <up & down game> will be O(nlogn), not O(logn), because, it is not binary search on the array
        int left = *std::max_element(weights.begin(), weights.end()); // can be a minimum capacity value
        int right = std::accumulate(weights.begin(), weights.end(), 0); // maximun capacity
        int mid = 0;
        
        while (left < right) {
            mid = left + (right - left) / 2;
            if (condition(weights, mid, days)) // mid value can be a capacity but there could be more smaller capacity value
                right = mid;
            else                // mid value is too small to be a capacity, so increasing it. and check condition again.
                left = mid + 1;  
        }
        return left;
    }
};