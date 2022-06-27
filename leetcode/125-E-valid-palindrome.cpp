// https://velog.io/@soopsaram/Leetcode-125.-Valid-Palindrome

#include <string>
class Solution {
public:
    string nomalize_str(string s) {
        std::string converted_s;
        for (auto c: s) {
            if ((c >= 'A' && c <= 'Z') ||
                (c >= 'a' && c <= 'z') ||
                (c >= '0' && c <= '9'))
                converted_s.push_back(std::tolower(c));
            else
                continue;
        }
        return converted_s;
    }

    bool isPalindrome(string s) {
        string new_s = nomalize_str(s);
        int left = 0;
        int right = new_s.size() - 1;
        while (left < right) {
            if (new_s[left++] != new_s[right--])
                return false;
        }
        return true;
    }
};
