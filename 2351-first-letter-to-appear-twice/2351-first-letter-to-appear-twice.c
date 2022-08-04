

char repeatedCharacter(char * s){
    int table[26] = {0};
    int ssize = strlen(s);
    for (int i = 0; i < ssize; i++) {
        if (table[s[i] - 'a'] == 1)
            return s[i];
        table[s[i] - 'a']++;
    }
    return s[0];
}