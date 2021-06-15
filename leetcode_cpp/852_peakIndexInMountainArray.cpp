class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        // 二分法
        int res(0);
        int l = arr.size();
        int p1(0), p2(l-1);
        int temp(0), middle(0);
        while (true) {
            middle = int((p1 + p2) / 2);
            temp = arr[middle];
            if (temp > arr[middle-1] && temp > arr[middle+1]) {
                return middle;
            } 
            else if (temp > arr[middle-1] && temp < arr[middle+1]) {
                p1 = middle;
            }
            else if (temp < arr[middle-1] && temp > arr[middle+1]) {
                p2 = middle;
            }
            else {
                return 0;
            }
        }
        return 0;
    }
};