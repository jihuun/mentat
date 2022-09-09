class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> stk; // idx, 
        vector<int> ans(temperatures.size(), 0);
        
        stk.push(0);
        for (int i = 1; i < temperatures.size(); i++) {
            //cout << temperatures[i] << "," <<  stk.top() << endl;
            while (!stk.empty() && temperatures[i] > temperatures[stk.top()]) {
                ans[stk.top()] = i - stk.top();
                stk.pop();
            }
            stk.push(i);
        }
        return ans;
    }
    
};