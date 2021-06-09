class Solution {
public:
    string convert(string s, int numRows) {
        // 找规律就好
        int l = s.size();
        if (l <= numRows || numRows == 1) {return s;}
        int numGroup = 2 * numRows - 2;
        int count = l / numGroup + int(l % numGroup > 0);
        string res = "";

        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < count; j++) {
                if (i == 0 || i == (numRows-1)) {
                    if ((j * numGroup + i) < l) {
                        res = res + s[j * numGroup + i];
                    } 
                } else {
                    if ((j * numGroup + i) < l) {
                        res = res + s[j * numGroup + i];
                    }
                    if ((j * numGroup + numGroup - i) < l) {
                        res = res + s[j * numGroup + numGroup - i];
                    }
                }
            }
        }

        return res;
    }
};