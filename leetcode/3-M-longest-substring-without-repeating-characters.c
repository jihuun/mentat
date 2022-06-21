
/*

   https://velog.io/@soopsaram/Leetcode-3.-Longest-Substring-Without-Repeating-Characters


1. constraint
 - 0 <= s.length <= 50000
 - s can be all letter
 -
2. Ideas
 - greedy way O(N) -> X
   - using hashtable to check repeated letter exist
 - brute force with Window size -> O(N^2)
 - sliding window with two pointer (l, r)
   - increase l, while (table[s[r]] > 1)
3. TC
*/
#define TABLE_SIZE 128

int lengthOfLongestSubstring(char * s) {
    int table[TABLE_SIZE] = {0,};
    int ssize = strlen(s);
    int max_len = 0;
    int left = 0, right = 0;

    while (right < ssize) {
        table[s[right]]++;
        while (table[s[right]] > 1) {
            table[s[left]]--;
            left++;
        }
        if ((right - left + 1) > max_len)
            max_len = right - left + 1;
        right++;
    }
    return max_len;
}
