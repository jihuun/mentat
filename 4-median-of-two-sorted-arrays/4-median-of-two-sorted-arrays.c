
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int retsize = nums1Size + nums2Size;
    int *ret = (int *)malloc(retsize * sizeof(int));
    int retcnt = 0;
    int i1 = 0, i2 = 0;
    
    while (retcnt < retsize) {
        if (i1 == nums1Size) {
            ret[retcnt++] = nums2[i2++];
            continue;
        }
        if (i2 == nums2Size) {
            ret[retcnt++] = nums1[i1++];
            continue;
        }
        if (nums1[i1] < nums2[i2]) {
            ret[retcnt++] = nums1[i1++];
        } else {
            ret[retcnt++] = nums2[i2++];
        }
    }
    
    int mid = retsize >> 1;
    if (retsize % 2 == 0)
        return (double)(ret[mid - 1] + ret[mid]) / 2;
    else 
        return ret[mid];
}