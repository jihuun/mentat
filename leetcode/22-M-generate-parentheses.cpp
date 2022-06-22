// https://velog.io/@soopsaram/Leetcode-22.-Generate-Parentheses

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        std::string parans;

        parans.append(n, '(');
        parans.append(n, ')');

        do {
            if (is_well_formed(parans)) {
                //cout << parans << " ";
                ret.push_back(parans);
            }
        } while (std::next_permutation(parans.begin(), parans.end()));

        return ret;
    }

    bool is_well_formed(string s) {
        std::stack<char> stk;
        for (char c: s) {
            if (c == '(')
                stk.push('(');
            else if (c == ')')
                if (!stk.empty())
                    stk.pop();
        }
        if (stk.empty())
            return true;
        else
            return false;
    }
};
