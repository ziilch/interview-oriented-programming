//
// Created by zorro on 2020/4/21.
//

#ifndef INTERVIEW_PROGRAMMING_LISTNODE_H
#define INTERVIEW_PROGRAMMING_LISTNODE_H

#include "../includes/BaseInclude.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class ListNodeSolution {
public:
    // M-L2-**
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
