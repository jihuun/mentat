/*
G C
1 3 -> -2 
2 4 -> -2
3 5 -> -2
4 1 ->  3
5 2 ->  3
*/
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int ssize = gas.size();
        int surplus = 0;
        int tot_surplus = 0;
        int idx = 0;
        
        for (int i = 0; i < ssize; i++) {
            surplus += gas[i] - cost[i];
            tot_surplus += gas[i] - cost[i];
            if (surplus < 0) {
                surplus = 0;
                idx = i + 1;
            }
        }
        return (tot_surplus < 0) ? -1 : idx;
        
    }
};