class Solution {
public:
    string decodeString(string s) {
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ']') {
                st.push(s[i]);
            } else {
                string curr_str = "";
                while (st.top() != '[') {
                    curr_str = st.top() + curr_str;
                    st.pop();
                }
                st.pop(); // '['
                
                string number = "";
                while (!st.empty() && isdigit(st.top())) {
                    number = st.top() + number;
                    st.pop();
                }
                int repeat = stoi(number);
                while (repeat--) {
                    for (int p = 0; p < curr_str.size(); p++)
                        st.push(curr_str[p]);
                }
            }
        }
        
        s = "";
        while(!st.empty()){
            s = st.top() + s;
            st.pop();
        }
        return s;
        
    }
};