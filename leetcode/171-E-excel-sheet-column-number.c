// https://velog.io/@soopsaram/Leetcode-171.-Excel-Sheet-Column-Number

int titleToNumber(char * columnTitle){
    long ret = 0;
    int csize = strlen(columnTitle);
    long mul = 1;

    for (int i = csize - 1; i >= 0; i--) {
        ret += (columnTitle[i] - 'A' + 1) * mul;
        mul *= 26;
    }
    return (int)ret;
}
