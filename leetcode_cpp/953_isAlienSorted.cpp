class Solution {
public:
    map<char, int> mOrderMap;

    bool isAlienSorted(vector<string>& words, string order) {
        if (words.size() <= 1) {
            return true;
        }

        for (int k = 0; k <=25; k++) {
            mOrderMap.insert(pair<char, int>(order[k], k));
        }

        int i = 0;
        int j = 1;
        while (compareWord(words[i], words[j], order)) {
            if (j == (words.size() - 1)) {
                return true;
            }
            i ++;
            j ++;
        }
        return false;
    }

    bool compareWord(string word1, string word2, string order) {
        int i = 0;
        while (i < word1.size() && i < word2.size()) {
            if (word1[i] == word2[i]) {
                i++;
                continue;
            }
            if (mOrderMap[word1[i]] < mOrderMap[word2[i]]) {
                return true;
            } else {
                return false;
            }
        }
        if (word1.size() <= word2.size()) {
            return true;
        } else {
            return false;
        }
    }
};