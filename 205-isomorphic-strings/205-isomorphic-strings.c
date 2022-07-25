bool isIsomorphic(char * s, char * t){
    char *s_table = (char *)calloc(128, sizeof(char));
    char *t_table = (char *)calloc(128, sizeof(char));
    int s_size = strlen(s);
    
    for (int i = 0; i < s_size; i++) {
        if (s_table[s[i]] && s_table[s[i]] != t[i])
            return false;
        if (t_table[t[i]] && t_table[t[i]] != s[i])
            return false;
        s_table[s[i]] = t[i];
        t_table[t[i]] = s[i];
    }
    return true;
}