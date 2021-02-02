class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int L1 = 0, R1 = nums1.size() - 1;
        int L2 = 0, R2 = nums2.size() - 1;
        int resL = 0, resR = 0;
        while (L1 <= R1 || L2 <= R2) {
            if (L2 > R2 || (L1 <= R1 && nums1[L1] < nums2[L2])) {
                resL = nums1[L1];
                ++L1;
            } else {
                resL = nums2[L2];
                ++L2;
            }
            if (L1 > R1 && L2 > R2)
                break;
            if (L2 > R2 || (L1 <= R1 && nums1[R1] > nums2[R2])) {
                resR = nums1[R1];
                --R1;
            } else {
                resR = nums2[R2];
                --R2;
            }
        }
        if ((nums1.size() + nums2.size()) % 2 == 0)
            return (resL + resR) / 2.0;
        else
            return resL;
    }
};