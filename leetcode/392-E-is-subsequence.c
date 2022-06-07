// https://velog.io/@soopsaram/Leetcode-392.-Is-Subsequence

bool isSubsequence(char *s, char *t){
    int tsize = strlen(t);
    if (*s == '\0' && *t == '\0')
        return true;
    for (int i = 0; i < tsize; i++) {
        if (*s == t[i])
            *s++;
        if (*s == '\0')
            return true;
    }
    return false;
}
