
#define max(a,b) (((a) > (b)) ? (a) : (b))
int characterReplacement(char * s, int k){
    int freq[26] = {0};
    int maxfreq = 0;
    int ssize = strlen(s);
    int left = 0, right = 0;
    int maxlen = 0;
    
    for (; right < ssize; right++) {
        /* update s[right] freq */
        freq[s[right] - 'A']++;
        maxfreq = max(maxfreq, freq[s[right] - 'A']);
        
        /* if target charactors to change is larger than k */
        if (right - left + 1 - maxfreq > k) {
            freq[s[left] - 'A']--;
            left++;
        } else {
            maxlen = max(right - left + 1, maxlen);
        }
    }
    return maxlen;
}