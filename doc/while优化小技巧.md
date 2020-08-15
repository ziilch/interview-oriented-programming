# while优化小技巧

[TOC]

## 一 目的

在题目需要多个循环的时候，节省while使用，将脑力更多的放在题目的思考上，减少边界问题的判断和状态的维护。

## 二 实例

拿一道题目来看，leetcode的第209题，这是一道双指针的题目。思路是固定的，下面看两种解法：

```
给定一个含有 n 个正整数的数组和一个正整数 s ，找出该数组中满足其和 ≥ s 的长度最小的 连续 子数组，并返回其长度。如果不存在符合条件的子数组，返回 0。

 

示例：

输入：s = 7, nums = [2,3,1,2,4,3]
输出：2
解释：子数组 [4,3] 是该条件下的长度最小的子数组。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-size-subarray-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```



- 解法1：使用了三个while循环

```c++
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size(), res = n, lt = 0, rt = 0, sum = 0;
        while (rt < n) {
            while (sum < s && rt < n) {
                sum += nums[rt ++];
            }
            res = min(res, rt - lt);
            if (sum < s) {
                return res < n ? res : 0;
            }
    
            while (sum >= s) {
                sum -= nums[lt ++];
            }
            res = min(res, rt - lt + 1);
        }
        return res;
    }
};
```



- 解法2：将一个循环套在另外一个循环之中

```c++
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int lt = 0, rt = 0, n = nums.size(), res = n + 1, sum = 0;
        while (rt < n) {
            sum += nums[rt ++];
            while (sum >= s) {
                sum -= nums[lt ++];
                res = min(res, rt - lt + 1);
            }
        }
        return res == n + 1 ? 0 : res;
    }
};
```

## 三 总结

题目思路为：右指针右移，找到一个区域和大于目标值，找到后，将左指针右移，直到左右指针之间的区域和小于目标值，周而复始，找到元素最少的区间。

解法一将上述的左指针右移和右指针右移视为两个对称的过程，在外围的while循环做判断什么时候退出。

解法二是将两个过程合二为一，是解法一的一种优化。