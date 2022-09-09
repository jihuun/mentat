class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> stk; // idx, temper
        
        stk.push(make_pair(0, temperatures[0]));
        temperatures[0] = 0;
        for (int i = 1; i < temperatures.size(); i++) {
            //cout << temperatures[i] << "," <<  stk.top().second << endl;
            while (!stk.empty() && temperatures[i] > stk.top().second) {
                temperatures[stk.top().first] = i - stk.top().first;
                stk.pop();
            }
            stk.push(make_pair(i, temperatures[i]));
            temperatures[i] = 0;
        }
        return temperatures;
    }
    
};