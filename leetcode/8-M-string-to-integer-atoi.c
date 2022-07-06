

int myAtoi(char * s){
    long retval = 0;
    int sign = 1;
    int signcheck = 0;
    bool during_convert = false;
    while (*s != '\0') {
        switch (*s) {
            case '-':
                if (during_convert)
                    return (int)sign * retval;
                if (signcheck != 0)
                    return 0;
                signcheck = 1;
                sign = -1;
                s++;
                continue;
            case '+':
                if (during_convert)
                    return (int)sign * retval;
                if (signcheck != 0)
                    return 0;
                signcheck = 1;
                sign = 1;
                s++;
                continue;
            case ' ':
                if (during_convert)
                    return (int)sign * retval;
                if (signcheck == 1)
                    return 0;
                s++;
                continue;
        }

        if (*s >= '0' && *s <= '9') {
            during_convert = true;
            retval *= 10;
            retval += *s - '0';
            if (sign *retval > INT_MAX) {
                return INT_MAX;
            } else if ((sign * retval) < INT_MIN) {
                return INT_MIN;
            }
        } else {
            if (during_convert)
                return (int)sign * retval;
            else
                return 0;
        }
        s++;
    }
    return (int) sign * retval;
}
