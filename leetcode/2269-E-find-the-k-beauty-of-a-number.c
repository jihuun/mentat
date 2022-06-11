//  https://velog.io/@soopsaram/Leetcode-2269.-Find-the-K-Beauty-of-a-Number

int divisorSubstrings(int num, int k){
    int retcnt = 0;
    char snum[11];
    sprintf(snum, "%d", num);
    int nsize = strlen(snum);

    char *substr = (char *)calloc(k + 1, sizeof(char));
    int sub = 0;
    for (int i = 0; i <= nsize - k; i++) {
        strncpy(substr, snum + i, k);
        sscanf(substr, "%d", &sub);
        if (sub == 0)
            continue;
        if (num % sub == 0) // always check devide by zero
            retcnt++;
    }
    return retcnt;
}
