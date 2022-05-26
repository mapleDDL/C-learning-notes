class Solution {
public:
    int findSubstringInWraproundString(string p) {
        if (p.size() == 1) { return 1; }
        int dp[p.size()];
        int record[26];
        for (int i = 0; i < p.size(); i++) { dp[i] = 0; }
        for (int i = 0; i < 26; i++) { record[i] = 0; }
        dp[0] = 1;
        record[p[0] - 'a'] = 1;
        for (int i = 1; i < p.size(); i++) {
            if (p[i] == (p[i-1] + 1) || (p[i] == 'a' && p[i-1] == 'z')) {
                int temp = dp[i-1] + 1;
                if (temp > record[p[i]-'a']) {
                    record[p[i]-'a'] = temp;
                    dp[i] = temp;
                } else {
                    dp[i] = temp;
                }
            } else {
                if (record[p[i]-'a'] == 0) { record[p[i]-'a'] = 1; }
                dp[i] = 1;
            }
        }

        int res = 0;
        for (int i = 0; i < 26; i++) { res += record[i]; }
        return res;
    }
};