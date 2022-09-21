class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> st; // index
        int hsize = height.size();
        int amount_water = 0;
        
        for (int i = 0; i < hsize; i++) {
            // if curr height >= then top of stack
            while (!st.empty() && height[i] >= height[st.top()]) {
                // -_-
                // 123   -> (3): curr height[i], (2): first st.top(), (3): second st.top()
                int u_shape_idx = st.top(); // the first st.top() is always 'U' shape position 
                st.pop();
                if (st.empty())
                    break;
                // this point st.top()'s height is always higher than height[u_shape_idx]
                int distance = i - st.top() - 1;
                int water_height = std::min(height[i], height[st.top()]) - height[u_shape_idx];
                amount_water += distance * water_height;
            }
            st.push(i);
        }
        return amount_water;
    }
};