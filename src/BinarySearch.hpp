//
// Created by zorro on 2020/4/19.
//
#ifndef INTERVIEW_PROGRAMMING_BINARRY_SEARCH
#define INTERVIEW_PROGRAMMING_BINARRY_SEARCH

#include "../includes/BaseInclude.h"
class BinarySearch {
public:

    // 难度：M leetcode 287 经典指数： *****
    // 给定一个包含 n + 1 个整数的数组 nums，其数字都在 1 到 n 之间（包括 1 和 n），可知至少存在一个重复的整数。
    // 假设只有一个重复的整数，找出这个重复的数。

    int findDuplicate(vector<int>& nums) {
        // 此题目要根据抽屉原理
        // n + 1个苹果要放到 n 个 盒子里面，那么必定有一个盒子装了两个苹果
        int l = 1, r = nums.size() - 1;
        while (l < r) {
            int m = (l + r) >> 1;
            int cnt = 0;
            // 判断小于等于中间数的数字有多少个，如果多了，说明重复数比中间数大
            for (auto num : nums) if (num <= m) cnt ++;
            if (cnt > m) r = m;
            else l = m + 1;
        }
        return l;
    }
};



#endif //INTERVIEW_PROGRAMMING_BINARRY_SEARCH
