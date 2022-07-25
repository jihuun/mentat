

bool isSubsequence(char *s, char *t) {
    int s_size = strlen(s);
    int t_size = strlen(t);
    int s_idx = 0, t_idx = 0;
    
    while (s_idx < s_size && t_idx < t_size) {
        if (s[s_idx] == t[t_idx])
            s_idx++;
        t_idx++;
    }
    return s_idx == s_size;
}