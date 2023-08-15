class Solution {
public:
    string reverseWords(string s) {
        stack<string> words;
        string sub = "";
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ' ') {
                if (sub.length() > 0) {
                    words.push(sub);
                    sub = "";
                }
            } else {
                sub += s[i];
            }
        }
        if (sub.length() > 0)
            words.push(sub);
        
        string ret = "";
        while (words.size() > 1) {
            ret += words.top() + " ";
            words.pop();
        }
        ret += words.top();
        return ret;
    }
};