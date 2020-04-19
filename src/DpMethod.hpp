//
// Created by zorro on 2020/4/19.
//
#include "../includes/BaseInclude.h"
class DpMethod {
public:

    // M难度：LeetCode 300
    // 给定一个无序的整数数组，找到其中最长上升子序列的长度。
    // 输入：[10,9,2,5,3,7,101,18] 输出：4
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        // 代表前n个
        vector<int> dp(n);

        for (int i = 0; i < n; ++i) {
            dp[i] = 1;
            for (int j = 0; j < i; ++j) if (nums[i] > nums[j]) dp[i] = max(dp[i], dp[j] + 1);
        }
        int res = 0;
        for (int i = 0; i < n; ++i) res = max(res, dp[i]);
        return res;
    }
};
