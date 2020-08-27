#ifndef INTERVIEW_PROGRAMMING_PUZZLE_H
#define INTERVIEW_PROGRAMMING_PUZZLE_H
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

}


#endif //INTERVIEW_PROGRAMMING_PUZZLE_H