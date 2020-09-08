//
// Created by zorro on 2020/4/19.
//
#ifndef INTERVIEW_PROGRAMMING_DP_METHOD
#define INTERVIEW_PROGRAMMING_DP_METHOD

#include "../includes/base_include.h"
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

    /**
     * J60-M-*
     * 本题可以用遍历做，但是会超时，所以采用动态规划
     * dp[i][j] = sum(k = 1, 6) dp[i - 1][j - k]
     * @param n
     * @return
     */
    vector<double> twoSum(int n) {
        vector<vector<double>> f(n, vector<double>(6 * n));
        vector<double> ans;
        double base = 1./6;
        for (int i = 0; i < 6; i ++) f[0][i] = base;
        for (int i = 1; i < n; i ++) {
            for (int j = i; j < (i + 1) * 6; j ++) {
                for (int k = 1; k < 7; k ++) {
                    if (j - k >= 0) f[i][j] += f[i - 1][j - k] * base;
                }
            }
        }
        for (int i = n - 1; i < n * 6; i ++) ans.push_back(f[n - 1][i]);
        return ans;
    }

    /**
     * L121-M-****
     * 股票的最大价值，这道题目太经典了，若不用dp会是n^2的复杂度
     * 这道题目的难点是如何确定状态转移方程
     * dp[i] = max(dp[i - 1], prices[i] - min(prices[0:i-1]))
     * dp[i]代表以prices[i]结尾的，也就是前i天的最大收益
     * @param prices
     * @return
     */
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int low = prices[0], res = 0;
        for (int i = 1; i < prices.size(); i ++) {
            res = max (res, prices[i] - low);
            low = min(low, prices[i]);
        }
        return res;
    }

    /**
     * J66-E-**
     * 这个题目的主要难点在于构建两个乘积数组L,R
     * 假设给定的数组长度为n，从0开始计数
     * L[i] = a[0]*...*a[i - 1], R[i] = a[n - i]*...*a[i+1]
     * 其中i = 0时i-1=-1,i = n-1时,i + 1=5，均溢出，根据提议，让L[0] = 1, R[4]=1
     * @param a
     * @return
     */
    vector<int> constructArr(vector<int>& a) {
        if (a.empty()) return a;
        int n = a.size();
        vector<int> l(n);
        vector<int> r(n);
        l[0] = 1;
        r[n - 1] = 1;
        for (int i = 1; i < n; i ++) {
            l[i] = l[i - 1] * a[i - 1];
            r[n - i - 1] = r[n - i] * a[n - i];
        }
        vector<int> res;
        for (int i = 0; i < n; i ++) {
            res.push_back(l[i] * r[i]);
        }
        return res;
    }

    /**
     * L55-M-***
     * 一种方法是用dfs做，遍历所有路径，但是会超时
     * 另一种方法就是假设是有这样一条路径存在的
     * 这样做有一个前提，就是如果能到达某个点，那么它之前的所有点一定都可达
     * 这样遍历所有点能到达的地方，每次把k遍历成最大能到达的地方
     * 什么时候不可达呢？就是i > k的时候
     * 说明我们遍历i的时候，i已经遍历到了一个k走不到的地方
     * 这时候就返回false
     * @param nums
     * @return
     */
    bool canJump(vector<int>& nums) {
        int k = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i > k) return false;
            k = max(k, i + nums[i]);
        }
        return true;
    }
};



#endif //INTERVIEW_PROGRAMMING_DP_METHOD