//
// Created by zorro on 2020/4/19.
//
#ifndef INTERVIEW_PROGRAMMING_DP_METHOD
#define INTERVIEW_PROGRAMMING_DP_METHOD

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

    /**
     * E-L53-***
     * 这个题目的难点就在于状态转移方程：只需要知道包含第i个数的数组状态即可
     * dp[i] = dp[i - 1] > 0 ? nums[i] + dp[i - 1] : nums[i]
     * @param nums
     * @return
     */
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        for (int i = 1; i < nums.size(); i ++) {
            dp[i] = dp[i - 1] > 0 ? dp[i - 1] + nums[i] : nums[i];
        }
        int max = dp[0];
        for (int i = 1; i < nums.size(); i ++) {
            if (dp[i] > max) max = dp[i];
        }
        return max;
    }
};



#endif //INTERVIEW_PROGRAMMING_DP_METHOD