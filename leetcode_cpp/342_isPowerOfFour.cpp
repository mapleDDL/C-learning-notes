class Solution {
public:
    bool isPowerOfFour(int n) {
        // 位运算，考虑越界。不要超过2**30
        if (n <= 0) {
            return false;
        }
        int res = 1; 
        int th = 1 << 30;
        while(res <= n) {
            if (n == res) {
                return true;
            }
            if (res == th) {
                break;
            } else {
                res = res << 2;
            }
        }
        return false;
    }
};