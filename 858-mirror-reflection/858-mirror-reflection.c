

int mirrorReflection(int p, int q){
    /* 최대 공약수로 p , q 를 나눠주기 */
    int com = q;
    for (; com > 0; com--) {
        if (p % com == 0 && q % com == 0)
            break;
    }
    p = p / com;
    q = q / com;

    if (q % 2 == 0) {
        if (p % 2 == 0)
            return -1;
        else
            return 0;
    } else {
        if (p % 2 == 0)
            return 2;
        else
            return 1;
    }
}