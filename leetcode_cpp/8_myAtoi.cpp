class Solution {
public:
    int myAtoi(string s) {
        //  同7，主要是考虑一些特殊情况
        if (s.size() == 0 || s == " ") {
            return 0;
        }
        bool zfflag = true;
        bool hasflag = false;
        long res = 0;
        int readValidNum = 0;
        int minVal = 0x80000000;
        int maxVal = 0x7FFFFFFF;
        for (auto i = s.begin(); i != s.end(); i++) {
            if (*i >= '0' && *i <= '9') {
                if (zfflag && (res * 10 + (*i-'0')) > maxVal) {
                    return maxVal;
                }
                if (!zfflag && -(res * 10 + (*i-'0')) < minVal) {
                    return minVal;
                }
                res = res * 10 + (*i-'0');
                readValidNum ++;

            } else if (*i == ' ') {
                if (readValidNum == 0) {
                    continue;
                } else {
                    return zfflag ? res : -res;
                }
            } else if (*i == '-' || *i == '+') {
                if (hasflag || (i+1)==s.end() || !(*(i+1) >= '0' && *(i+1) <= '9')) {
                    cout << *i << endl;
                    return zfflag ? res : -res;
                }
                if (readValidNum != 0) {
                    return zfflag ? res : -res;
                } else {
                    zfflag = (*i == '+') ? true : false;
                }
                hasflag = true;

            } else {
                return zfflag ? res : -res;
            }
        }
        return zfflag ? res : -res;
    }
};