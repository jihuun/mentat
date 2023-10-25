class Solution {
public:
    bool is_vowel(char c) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            return true;
        return false;
    }
    int maxVowels(string s, int k) {
        int vcnt = 0;
        for (int i = 0; i < k; i++) {
            if (is_vowel(s[i]))
                vcnt++;
        }
        int max_vcnt = vcnt;
        int past = 0;
        for (int i = k; i < s.length(); i++) {
            if (is_vowel(s[i]))
                vcnt++;
            if (is_vowel(s[past++]))
                vcnt--;
            max_vcnt = max(vcnt, max_vcnt);
        }
        return max_vcnt;
    }
};