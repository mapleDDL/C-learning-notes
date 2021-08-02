class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        vector<int> vec;
        int temp = 0;
        while (x){
            temp = x % 10;
            x = (x - temp) / 10;
            vec.push_back(temp);
        }
        if (vec.size() == 0) {
            return true;
        }
        auto beg = vec.begin();
        auto rbeg = vec.end() - 1;
        while (beg != vec.end()) {
            if (*beg != *rbeg) {
                return false;
            } else {
                beg ++;
                rbeg --;
            }
        }
        return true;

    }
};