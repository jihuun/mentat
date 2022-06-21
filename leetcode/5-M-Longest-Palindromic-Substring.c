// Longest-Palindromic-Substring
// https://velog.io/@soopsaram/Leetcode-5.-Longest-Palindromic-Substring

int expand_around_center(char *str, int left, int right, int ssize)
{
    int len = 0;
    while (left >= 0 && right < ssize && str[left] == str[right]) {
        len = right - left + 1;
        left--;
        right++;
    }
    return len;
}

char *longestPalindrome(char * s){
    int cur_len = 0;
    int len_odd = 0;
    int len_even = 0;
    int start = 0, end = 0;
    int ssize = strlen(s);
    
    for (int i = 0; i < ssize; i++) {
        len_odd = expand_around_center(s, i, i, ssize);
        len_even = expand_around_center(s, i, i+1, ssize);
        cur_len = len_odd > len_even ? len_odd: len_even;
        if (cur_len > end - start + 1) {
            // if current position has more larger palindrome, update start/end index
            start = i - ((cur_len - 1) / 2); // this calc is works for both of odd/even case
            end = i + (cur_len / 2);
        }
    }
    cur_len = end - start + 1;
    char *ret = (char *)malloc(sizeof(char) * (cur_len + 1));
    for (int i = 0; i < cur_len; i++)
        ret[i] = s[start++];
    ret[cur_len] = '\0';
    return ret;
}

