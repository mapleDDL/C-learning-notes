class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() <= 1) {
            return s.length();
        } 
        vector<char> buffer;
        int res = 0;
        for (int i = 0; i < s.length(); i++) {
            for (auto iter = buffer.begin(); iter != buffer.end(); iter++) {
                if(*iter==s[i]) {
                    while (*buffer.begin() != s[i]) {
                        buffer.erase(buffer.begin());
                    }
                    buffer.erase(buffer.begin());
                    break;
                }
            }
            buffer.push_back(s[i]);
            if (buffer.size() > res) {
                res = buffer.size();
            }
        }
        return res;
    }
};