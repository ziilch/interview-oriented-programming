#ifndef INTERVIEW_PROGRAMMING_PUZZLE_H
#define INTERVIEW_PROGRAMMING_PUZZLE_H
#include "../includes/base_include.h"

class PuzzleProblem {
public:

    // L31-M-****
    // 这个题目的思路为从后到前找到第一个顺序排列的两个数：比如 12354687，这两个数就是6和8
    // 为什么要找这两个数呢？用倒推法：一个排列组合什么时候是最大的数呢？当它完全是倒序的时候：12345->54321
    // 这个题目找的是比给定的数大的下一个排列，那么如果从后往前一直都是升序的，说明这一段就没有比它更大的数
    // 我们知道，数字越在前，占的比重越大，那么，我们的目标就是最好前面都不变，这个能出现比当前数大的数字，位数越靠后越好
    // 所以就是要从后往前数，找到第一个升序的数，和它后面刚好比它大的数进行互换
    // 互换后，假如当前位置是i，那么i + 1到end一定是一个由大到小的排列，只需将它倒过来，就是一个升序的数组
    // 根据我们之前的描述我们知道，升序的数组是最小的，这样我们就找到了第一个比当前排列大的数
    void nextPermutation(vector<int>& nums) {
        if (nums.size() < 2) return;
        int ft = -1;
        for (int i = nums.size() - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                ft = i;
                break;
            } 
        }
        //cout << ft << endl;
        if (ft == -1) {
            reverse(nums.begin(), nums.end());
        } else {
            for (int i = nums.size() - 1; i > ft; i--) {
                if (nums[i] > nums[ft]) {
                    swap(nums[i], nums[ft]);
                    //cout << nums[0] << endl;
                    break;
                } 
            }
            reverse(nums.begin() + ft + 1, nums.end());
        }
    }

    /**
     * L48-M-***
     * 这道题目的难点在于原地旋转
     * 原地旋转的话为了保持不新增变量，需要一次旋转四个位置
     * 这里面有两个小技巧
     * 一个是四个位置的相对位置都是对称的，都可以由第一个位置公式推导出，只要带入不同的横纵坐标就行了
     * 第二个是合理利用技巧可以只更改临时变量一次
     * 还有一个问题是确立哪些数字需要变换位置呢
     * 我们知道如果边长是奇数的话，那么矩阵中心位置不需要变动
     * 因为一次变动四个点，所以选择变动基数时，变动基数的长度一定是(n^2 - 1) / 4;
     * 如果边长是偶数，那么基数的长度就是(n^2) / 4;
     * 以边长为3为例，变动基数为2，选择第一行的头两个元素可以，选择第一列的头两个元素也行
     * 边长为4时，就要选择00，01，10，11四个元素
     * 边长为6时选择左上角一个2 * 3的矩阵
     * @param matrix
     */
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int tmp;
        for (int i = 0; i < (n + 1) / 2; i++) {
            for (int j = 0; j < n / 2; j++) {
                tmp = matrix[i][j];
                matrix[i][j] = matrix[n - j - 1][i];
                matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1];
                matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];
                matrix[j][n - i - 1] = tmp;
            }
        }
    }

};


#endif //INTERVIEW_PROGRAMMING_PUZZLE_H