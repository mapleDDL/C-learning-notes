class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // 为了不额外开辟空间，写的有点麻烦，主要思路是提前算好中位数是第几个，再一个个读就好了
        int l1 = nums1.size(), l2 = nums2.size();
        int l = l1 + l2;
        int resIndex;
        if (l % 2 == 0) {
            resIndex = l / 2 + 1;
        } else {
            resIndex = (l + 1) / 2;
        }
        // 这里temp主要是方便偶数个数时的计算
        double res = 0.0;
        int temp = 0, p1 = 0, p2 = 0;
        while (p1 + p2 < l) {
            if (p1 == l1) {
                temp = nums2[p2];
                p2 ++;
            } else if (p2 == l2) {
                temp = nums1[p1];
                p1 ++;
            } else {
                if (nums1[p1] < nums2[p2]) {
                    temp = nums1[p1];
                    p1 ++;
                } else {
                    temp = nums2[p2];
                    p2 ++;
                }
            }
            
            if (p1 + p2 == resIndex){
                if (l % 2 == 0) {
                    res = (res + temp) / 2.0;
                    break;
                } else {
                    res = temp * 1.0;
                    break;
                }
            } else {
                res = temp;
            }
        }

        return res;
    }
};