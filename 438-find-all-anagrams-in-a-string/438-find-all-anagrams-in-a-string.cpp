class Solution {
    bool is_table_same(int *st, int *pt) {
        for (int i = 0; i < 26; i++) {
            if (st[i] != pt[i])
                return false;
        }
        return true;
    }
        
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ret;
        int ssize = s.size();
        int psize = p.size();
        if (ssize < psize)
            return ret;
        int stable[26] = {0};
        int ptable[26] = {0};
        
        for (int i = 0; i < psize; i++) {
            ptable[p[i] - 'a']++;
            stable[s[i] - 'a']++;
        }
        if (is_table_same(stable, ptable))
            ret.push_back(0);
        
        for (int i = 1; i <= ssize - psize; i++) {
            stable[s[i - 1] - 'a']--;
            stable[s[i + psize - 1] - 'a']++;
            if (is_table_same(stable, ptable))
                ret.push_back(i);
        }
        return ret;
    }
};