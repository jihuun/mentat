class Solution {
    int rsize;
    int csize;
    int **visited;
    void expanding(vector<vector<int>>& image, int sr, int sc, int from_c, int to_c) {
        if (sr < 0 || sr >= rsize)
            return;
        if (sc < 0 || sc >= csize)
            return;
        if (visited[sr][sc] == 1)
            return;
        if (image[sr][sc] != from_c)
            return;
            
        if (image[sr][sc] == from_c) {
            image[sr][sc] = to_c;
        }
        visited[sr][sc] = 1;
        expanding(image, sr-1, sc, from_c, to_c);
        expanding(image, sr+1, sc, from_c, to_c);
        expanding(image, sr, sc-1, from_c, to_c);
        expanding(image, sr, sc+1, from_c, to_c);
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int from_color = image[sr][sc];
        rsize = image.size();
        csize = image[0].size();
        visited = (int **)calloc(rsize, sizeof(int *));
        for (int i = 0; i < rsize; i++)
            visited[i] = (int *)calloc(csize, sizeof(int));
        
        expanding(image, sr, sc, from_color, color);
        return image;
    }
};