//
// Created by zorro on 2020/4/19.
//
#ifndef INTERVIEW_PROGRAMMING_BINARRY_SEARCH
#define INTERVIEW_PROGRAMMING_BINARRY_SEARCH

#include "../includes/base_include.h"
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

    // M-L33-***
    // 假设按照升序排序的数组在预先未知的某个点上进行了旋转。
    //( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。
    //搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。
    int search(vector<int>& nums, int target) {
//        if (nums.size() == 0) return -1;
//        int left = 0, right = nums.size() - 1, mid = (left + right) >> 1;
//        while (left < right) {
//            // 先找到有序的区间，判断target是不是在有序区间内，如果不在，就是在另外一个区间
//            if (nums[left] <= nums[mid]) {
//                // 说明left到mid区间有序，看target是不是在区间内
//                if (nums[left] <= target && target <= nums[mid]) right = mid;
//                else left = mid + 1;
//                mid = (left + right) >> 1;
//            } else {
//                // 说明mid到right区间有序
//                if (nums[mid] <= target && target <= nums[right]) left = mid;
//                else right = mid - 1;
//                mid = (left + right + 1) >> 1;
//            }
//        }
//        return nums[left] == target ? left : -1;
        if (nums.empty()) return -1;
        // 首先用二分法找到数组中第一个小于首个元素的位置
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = (left + right) >> 1;
            if (nums[mid] < nums[0]) right = mid;
            else left = mid + 1;
        }

        if (nums[0] < nums[left]) {
            // 假如根本就没旋转
            left = 0, right = nums.size() - 1;
        } else {
            // 按照题目描述的正常进行了旋转
            int gap  = left;
            // 接下来对两段区间分别进行搜索
            if (nums[0] > target) left = gap, right = nums.size() - 1;
            else left = 0, right = gap - 1;
        }

        while(left < right) {
            int mid = (left +right + 1) >>1;
            if (nums[mid] <= target) left = mid;
            else right = mid - 1;
        }
        if (nums[left] != target) return -1;
        return left;
    }
};



#endif //INTERVIEW_PROGRAMMING_BINARRY_SEARCH
