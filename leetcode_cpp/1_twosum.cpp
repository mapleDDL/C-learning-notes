class Solution {
public:
// 暴力法
    vector<int> twoSum1(vector<int>& nums, int target) {
        int l = nums.size(); 
        for (int i = 0; i < l-1; i++) {
            for (int j = i+1; j < l; j++) {
                if ((nums[i] + nums[j]) == target) {
                    return {i,j};
                }
            }
        }
        return {-1,-1};
    }

// map 实现版本 空间换时间
    vector<int> twoSum2(vector<int>& nums, int target) {
        int l = nums.size(); 
        map<int,int> m;
        for (int i = 0; i < l; i ++ ) {
            m[nums[i]] = i;
        }

        for (int i = 0; i < l; i ++ ) {
            auto it = m.find(target-nums[i]);
            if (it != m.end() && it->second != i) {
                return {i, it->second};
            }
        }
        return {-1,-1};
    }
};
