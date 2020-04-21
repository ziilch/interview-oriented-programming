//
// Created by zorro on 2020/4/21.
//
#ifndef INTERVIEW_PROGRAMMING_SELF_UTIL
#define INTERVIEW_PROGRAMMING_SELF_UTIL

class SelfUtil{
public:
    // 生成随机数组，默认数组大小为10000，数组内数据在10000以内
    vector<int> createRandom(int valNum = 10000, int valRange = 10000) {
        vector<int> array(valNum);
        for(int i = 0; i < valNum; ++i) array[i] = (rand() % valRange);
        return array;
    }
};

#endif INTERVIEW_PROGRAMMING_SELF_UTIL
