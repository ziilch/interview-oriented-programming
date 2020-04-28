//
// Created by zorro on 2020/4/21.
//
#ifndef INTERVIEW_PROGRAMMING_SELF_UTIL
#define INTERVIEW_PROGRAMMING_SELF_UTIL

#include "../includes/BaseInclude.h"

class SelfUtil{
public:
    // 生成随机数组，默认数组大小为10000，数组内数据在10000以内
    vector<int> createRandom(const int valNum = 10000, const int valRange = 10000) {
        vector<int> array(valNum);
        for(int i = 0; i < valNum; ++i) array[i] = (rand() % valRange);
        return array;
    }

    // "1,2,3,45" --> 1->2->3->45
    ListNode* listNodeFromString (const string ss) {
        if (ss.empty())
            return NULL;
        ListNode* res = new ListNode(0);
        ListNode* cur = res;
        string tmp = "";
        for (int i = 0; i < ss.size(); i++) {
            if (ss[i] == ',') {
                cur->next = new ListNode(atoi(tmp.c_str()));
                cur = cur->next;
                tmp = "";
            } else {
                tmp += ss[i];
            }
        }
        cur->next = new ListNode(atoi(tmp.c_str()));
        cur = cur->next;
        cur->next = NULL;
        return res->next;
    }
};

#endif //INTERVIEW_PROGRAMMING_SELF_UTIL