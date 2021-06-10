class Solution {
public:
    int reverse(int x) {
        // 主要是考虑一些特殊情况
        long res(0);
        int sig(0);
        if (x < 0) {
            if (x == -2147483648) {
                return 0;
            }
            x = -x;
            sig = 1;
        }
        while (x > 0) {
            res = res * 10 + x % 10;
            x = (x - x % 10) / 10;
            if (res > 2147483648) {
                return 0;
            }
        }
        return sig ? -res : res;
    }
};