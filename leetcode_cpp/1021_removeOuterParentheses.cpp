class Solution {
public:
    string removeOuterParentheses(string s) {
        if (s.size() <= 1) { return s; }
        int leftNum = 0;
        int rightNum = 0;
        string res = "";
        string temp = "";

        for (int i = 0; i <= s.size(); i++) {
            if (s[i] == ')') {
                rightNum += 1;
            } else {
                leftNum += 1;
            }
            if (rightNum > leftNum) {
                res += ")";
            } else if (rightNum == leftNum) {
                res += temp;
                temp     = "";
                leftNum  = 0;
                rightNum = 0;
            } else {
                if (leftNum == 1) {
                    continue;
                } else {
                    temp += s[i];
                }
            }
        }

        return res;

    }
};