class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        // idx of sentence / how many word in a line
        unordered_map<int, int> table; 
        int idx = 0;
        int ssize = sentence.size();
        int num = 0;
        
        for (int i = 0; i < rows; i++) {
            idx = num % ssize;
            if (table.count(idx) == 0) {
                // if new, calculate number of words in a line from begin with sentence[idx]
                int cnt = 0, len = 0;
                int j = idx;
                while (len < cols) {
                    j = (j + 1) % ssize;
                    if (len + sentence[j].size() > cols)
                        break;
                    len += sentence[j].size() + 1;
                    cnt++;
                }
                num += cnt;
                table[idx] = cnt;
            } else {
                // if exist, just return from hashtable
                num += table[idx];
            }
        }
        return num / ssize;
    }
};