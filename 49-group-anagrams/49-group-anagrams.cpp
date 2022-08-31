class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ret;
        vector<string> orig;
        unordered_map<string, vector<int>> freq;
        
        /* sort strs and make orig vector */
        for (auto &s: strs) {
            orig.push_back(s);
            sort(s.begin(), s.end());
        }
        
        /* generate freq hashtable (key:string value: vector of index) */
        for (int i = 0; i < orig.size(); i++) {
            freq[strs[i]].push_back(i);
        }
        
        /* grouping via hashtable */
        for (auto f: freq) {
            vector<string> tmp;
            for (auto idx: f.second) /* f.second is a vector of index */
                tmp.push_back(orig[idx]);
            ret.push_back(tmp);
        }
        
        return ret;
    }
};