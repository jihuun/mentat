class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        stack<int> s;
        int r = 0;
        int exp = false;
        for (int i = 0; i < ast.size(); i++) {
            if (s.size() > 0 && ((s.top() > 0 && ast[i] > 0) || (s.top() < 0 && ast[i] > 0))) {
                // ..,2,3  ..,-2,3
                s.push(ast[i]);
                continue;
            }
            
            while (!s.empty() && (s.top() > 0 && ast[i] < 0) &&  abs(s.top()) <= abs(ast[i])) {
                // ..,2,-3  ..,2,-3 
                if (abs(s.top()) == abs(ast[i])) {
                    s.pop();
                    exp = true;
                    break;
                }
                s.pop();
            }
            if (exp) {
                exp = false;
                continue;
            }
            if (s.empty())
                s.push(ast[i]);
            else if (s.top() < 0 && ast[i] < 0)
                s.push(ast[i]);
        }
        
        vector<int> ret;
        while (!s.empty()) {
            ret.push_back(s.top());
            s.pop();
        }
        if (ret.size() == 0)
            return ret;
        reverse(ret.begin(), ret.end());
        return ret;
    }
};