// https://velog.io/@soopsaram/Leetcode-252.-Meeting-Rooms


int cmp(const void *a, const void *b)
{
    int *aval = *(int **)a;
    int *bval = *(int **)b;
    return aval[0] - bval[0];
}

bool canAttendMeetings(int** intervals, int intervalsSize, int* intervalsColSize){
    qsort(intervals, intervalsSize, sizeof(int *), cmp);
    for (int i = 0; i < intervalsSize - 1; i++)
        if (intervals[i][1] > intervals[i + 1][0])
            return false;
    return true;
}
