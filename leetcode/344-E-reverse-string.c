/**
 * https://leetcode.com/problems/reverse-string/
 *
 */

void reverseString(char* s, int sSize){
    for (int i = 0; i < sSize / 2; i++) {
        char tmp = s[i];
        s[i] = s[sSize - i - 1];
        s[sSize - i - 1] = tmp;
    }    
}
