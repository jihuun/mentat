//  https://velog.io/@soopsaram/Leetcode-88.-Merge-Sorted-Array

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int st_m = n;
    int st_n = 0;
    int arrcnt = 0;
    
    for (int i = nums1Size - n - 1; i >= 0; i--)
        nums1[i + n] = nums1[i];

    while (arrcnt < nums1Size) {
        if (st_m >= nums1Size) {
            nums1[arrcnt++] = nums2[st_n++];
            continue;
        }
        if (st_n >= nums2Size) {
            nums1[arrcnt++] = nums1[st_m++];
            continue;
        }
        if (nums1[st_m] > nums2[st_n])
            nums1[arrcnt++] = nums2[st_n++];
        else
            nums1[arrcnt++] = nums1[st_m++];
    }
}
