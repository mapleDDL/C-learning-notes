class Solution {
public:
    string longestPalindrome(string s) {
        // 二维动态规划，好像还是差了点，想想能不能一维的 
        int l = s.size();
        if (l == 0) {
            return 0;
        }
        string res;
        int maxLen = 0;
        vector<vector<int>> dp(l, vector<int>(l, 0));
        for (int i = l-1; i >= 0; i--) {
            for (int j = 0; j < l; j++) {
                if (i > j) {continue;}
                if (i == j) {
                    dp[i][j] = 1;
                    if (dp[i][j] > maxLen) {
                        maxLen = dp[i][j];
                        res = s.substr(i, maxLen);
                    }
                    continue;
                }
                if (i == (j-1)) {
                    dp[i][j] = 2 * int(s[i]==s[j]);
                    if (dp[i][j] > maxLen) {
                        maxLen = dp[i][j];
                        res = s.substr(i, maxLen);
                    }
                    continue;
                }
                if (s[i] == s[j] && dp[i+1][j-1] > 0) {
                    dp[i][j] = dp[i+1][j-1] + 2;
                    if (dp[i][j] > maxLen) {
                        maxLen = dp[i][j];
                        res = s.substr(i, maxLen);
                    }
                } 
            }
        }
        return res;
    }
};