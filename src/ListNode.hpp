//
// Created by zorro on 2020/4/21.
//

#ifndef INTERVIEW_PROGRAMMING_LISTNODE_H
#define INTERVIEW_PROGRAMMING_LISTNODE_H

#include "../includes/BaseInclude.h"

class ListNodeSolution {
public:

    // E-L206-*****
    ListNode* reverseList(ListNode* head) {
        ListNode* cur = head;
        ListNode* pre = NULL;
        ListNode* post = NULL;
        while (cur) {
            post = cur->next;
            cur->next = pre;
            pre = cur;
            cur = post;
        }
        return pre;
    }


    // M-L2-**
    // 输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
    //输出：7 -> 0 -> 8
    //原因：342 + 465 = 807
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int bp = 0;
        ListNode * res = new ListNode(0);
        ListNode* cur = res;
        while (l1 || l2) {
            int v1 = l1 ? l1->val : 0;
            int v2 = l2 ? l2->val : 0;
            int sum = v1 + v2 + bp;
            bp = sum / 10;
            cur->next = new ListNode(sum % 10);
            cur = cur->next;
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        if (bp) cur->next = new ListNode(1);
        return res->next;
    }


};


#endif //INTERVIEW_PROGRAMMING_LISTNODE_H
