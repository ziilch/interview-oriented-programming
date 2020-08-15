//
// Created by zilch on 2020/6/28.
//

#ifndef INTERVIEW_PROGRAMMING_BITOPERATION_HPP
#define INTERVIEW_PROGRAMMING_BITOPERATION_HPP

#include "../includes/base_include.h"

class BitOperation {
public:
    /**
     * J56-M-*
     * 这种题属于做了就会，不做一定不会的，面试如果出这种题目说明面试官有毛病
     *
     * @param nums
     * @return
     */
    vector<int> singleNumbers(vector<int>& nums) {
        int s = nums[0];
        for (int i = 1; i < nums.size(); i++) s ^= nums[i];
        int m = 1;
        while ((s & m) == 0) m <<= 1;// 这步的意义可以看tips 5
        int a = s, b = s;
        // 为什么要找到s中的1呢？因为两个不同的数a,b，只有在某一位上不同，才能出现1，通过判断这一位是否为1，就能将整个nums数组分成两部分
        // 重复的元素在哪一部分并不重要，因为他们都会被分到同一个部分，通过异或会把他们消掉
        for (int i = 0; i < nums.size(); i ++) {
            if ((nums[i] & m)) a ^= nums[i];
            if ((nums[i] & m) == 0) b ^= nums[i];
        }
        return {a, b};
    }

    /**
     * J56II-M-*
     * 一个数组，有一个数只出现一次，其余出现三次，思路：
     * 对这个数组的每一个数字的每一位进行相加，并%3，则出现三次的除余清零，出现一次的留下
     * 这样做31次，因为第一位是符号位，都是正数，所以不用管
     * 得到31个0或者1，然后对其进行次乘指数为后相加即可
     * 这里面有一个小问题，除余的时候不是得到二进制的1，二是会乘上当前的位：
     * 也就是nums[i] & bit假如说nums[i]的第二位是1，那么& 得到的不是1，二是2
     * 这样的话后面再进行余数操作就不对了，所以每次要转换为二进制
     * 还有一种思路是将nums右移见singleNumber2
     * @param nums
     * @return
     */
    int singleNumber(vector<int>& nums) {
        int bit = 1, res = 0;
        long long m = 1;
        for (int i = 0; i < 31; i ++) {
            int sum = 0;
            for (int j = 0; j < nums.size(); j ++) {
                sum += (nums[j] & bit) / m;
            }
            res += (sum % 3) * m;
            m *= 2;
            bit <<= 1;
        }
        return res;
    }

    int singleNumber2(vector<int>& nums) {
        int res = 0;
        long long m = 1;
        for (int i = 0; i < 31; i ++) {
            int sum = 0;
            for (int j = 0; j < nums.size(); j ++) {
                sum += ((nums[j] >> i) & 1);
            }
            res += (sum % 3) * m;
            m *= 2;
        }
        return res;
    }
};


#endif //INTERVIEW_PROGRAMMING_BITOPERATION_HPP
