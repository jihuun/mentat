//

bool isPowerOfThree(int n){
    long val = 1;
    while (val <= n) {
        if (val == n)
            return true;
        val *= 3;
    }
    return false;
}
