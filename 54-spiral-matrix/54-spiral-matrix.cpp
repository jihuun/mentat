class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rsize = matrix.size();
        int csize = matrix[0].size();
        int nr_elem = rsize * csize;
        vector<int> ret;
        // right, down, left, up
        int right = csize - 1;
        int down = rsize - 1;
        int left = 0;
        int up = 0;
        
        while (1) {
            // left -> right
            for (int col = left; col <= right; col++)
                ret.push_back(matrix[up][col]);
            if (ret.size() >= nr_elem) break;
            // up -> down
            for (int row = up + 1; row <= down; row++)
                ret.push_back(matrix[row][right]);
            if (ret.size() >= nr_elem) break;
            // right -> left
            for (int col = right - 1; col >= left; col--)
                ret.push_back(matrix[down][col]);
            if (ret.size() >= nr_elem) break;
            // down -> up
            for (int row = down - 1; row > up; row--)
                ret.push_back(matrix[row][left]);
            if (ret.size() >= nr_elem) break;
            
            right--;
            down--;
            left++;
            up++;
        }
        return ret;
    }
};