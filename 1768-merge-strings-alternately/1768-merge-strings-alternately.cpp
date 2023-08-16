class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        if (word1.size() == 0) return word2;
        if (word2.size() == 0) return word1;

        string ret = "";
        ret = ret + word1[0] + word2[0];
        return ret + mergeAlternately(word1.substr(1), word2.substr(1));
    }
};