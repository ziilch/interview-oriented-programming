//
// Created by zilch on 2020/8/14.
//

#ifndef INTERVIEW_PROGRAMMING_DOUBLEPOINTER_H
#define INTERVIEW_PROGRAMMING_DOUBLEPOINTER_H
class DoublePointer {
public:
    /**
     * L75-M-****
     * 感觉这是一道比较经典的题目
     * 有三种不同类型的组合，但是采用双指针的办法
     * 这样把区间分为三个部分：左指针前，左指针到右指针之间的区间，和右指针后
     * @param nums
     */
    void sortColors(vector<int>& nums) {
        int lf = 0, rt = nums.size() - 1, cur = 0;
        while (cur <= rt) {
            if (nums[cur] == 0) {
                swap(nums[cur ++], nums[lf ++]);
            }else if (nums[cur] == 2) {
                swap(nums[cur], nums[rt --]);
            } else {
                cur ++;
            }
        }
    }

    /**
     * L209-M-**
     * 这是一道很明显的双指针问题
     * 双指针最重要的问题就是边界问题
     * 还有就是如何实现双指针的驱动
     * @param s
     * @param nums
     * @return
     */
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


#endif //INTERVIEW_PROGRAMMING_DOUBLEPOINTER_H
